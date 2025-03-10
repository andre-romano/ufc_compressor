
#include "CompressionEstimator.hpp"

using CompressionInfo = CompressionEstimator::CompressionInfo;

namespace fs = std::filesystem;

// Constructor (optional, can be used for initialization)
CompressionEstimator::CompressionEstimator(const std::string &filePath,
                                           int sampleSize)
    : filePath(filePath), sampleSize(sampleSize) {}

/****************
 *   PUBLIC    *
 ****************/

// estimateCompression estimates the compressed file size based on file type and
// entropy
CompressionInfo CompressionEstimator::estimate_compression() {
  CompressionInfo compressionInfo;
  compressionInfo.file = filePath;

  // Get file size
  if (!fs::exists(filePath)) {
    throw std::runtime_error("file does not exist: " + filePath);
  }
  compressionInfo.original_size = fs::file_size(filePath);

  // Retrieve the compression ratio from the map
  std::string extension = fs::path(filePath).extension().string();
  auto it = CompressionEstimator::COMPRESSION_RATIOS.find(extension);
  double compressionRatio =
      CompressionEstimator::COMPRESSION_RATIOS.at("other");
  if (it != CompressionEstimator::COMPRESSION_RATIOS.end()) {
    compressionRatio = it->second;
  }

  // Adjust based on entropy
  double entropy = this->estimate_entropy();
  double entropyFactor = (1 - entropy) * 0.5 + 0.5; // Scale between 0.5 to 1
  compressionInfo.compression_ratio = compressionRatio * entropyFactor;

  // Estimated compressed size
  compressionInfo.compressed_size = static_cast<int64_t>(
      compressionInfo.original_size * compressionInfo.compression_ratio);

  return compressionInfo;
}

/****************
 *   PRIVATE    *
 ****************/

// estimateEntropy calculates the entropy of a file using a small sample
double CompressionEstimator::estimate_entropy() {
  std::ifstream file(this->filePath, std::ios::binary);
  if (!file) {
    throw std::runtime_error("failed to open file: " + filePath);
  }

  // Read sample data
  std::vector<char> data(this->sampleSize);
  file.read(data.data(), this->sampleSize);
  size_t nData = file.gcount(); // Number of bytes actually read

  if (nData == 0) {
    throw std::runtime_error("file is empty: " + filePath);
  }

  // Calculate byte frequencies
  std::map<char, double> freq;
  for (size_t i = 0; i < nData; ++i) {
    freq[data[i]]++;
  }

  // Calculate entropy
  double entropy = 0.0;
  for (const auto &[byte, count] : freq) {
    double p = count / nData;
    entropy -= p * log2(p);
  }

  return entropy / 8; // Normalize (1 = max entropy, 0 = no entropy)
}
