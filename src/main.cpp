#include <fstream>
#include <iostream>

#include "utils/CompressionEstimator.hpp"

int main(int argc, char *argv[]) {
  // Example usage
  std::string filePath = "example.txt"; // Change to any file
  try {
    auto estimator = CompressionEstimator(filePath);
    auto result = estimator.estimate_compression();
    std::cout << "File: " << result.file << "\n"
              << "Original Size: " << result.original_size << " bytes\n"
              << "Compression Ratio: " << result.compression_ratio << "\n"
              << "Estimated Compressed Size: " << result.compressed_size
              << " bytes\n";
  } catch (const std::exception &e) {
    std::cerr << "ERROR: " << e.what() << "\n";
    return 1;
  }

  return 0;
}