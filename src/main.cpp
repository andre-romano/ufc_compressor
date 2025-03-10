#include <fstream>
#include <iostream>

#include "CompressionEstimator.hpp"

using CompressionInfo = CompressionEstimator::CompressionInfo;

int main() {
  // Example usage
  std::string filePath = "example.txt"; // Change to any file
  try {
    auto estimator = CompressionEstimator(filePath);
    CompressionInfo result = estimator.estimateCompression();
    std::cout << "File: " << result.file << "\n"
              << "Original Size: " << result.originalSize << " bytes\n"
              << "Compression Ratio: " << result.compressionRatio << "\n"
              << "Estimated Compressed Size: " << result.estimatedCompressedSize
              << " bytes\n";
  } catch (const std::exception &e) {
    std::cerr << "ERROR: " << e.what() << "\n";
    return 1;
  }

  return 0;
}