#ifndef COMPRESSION_ESTIMATOR_H
#define COMPRESSION_ESTIMATOR_H

#include <algorithm>
#include <cmath>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <stdexcept>
#include <vector>

class CompressionEstimator {
public:
  // CompressionInfo struct
  struct CompressionInfo {
    double compressionRatio;         // between 0.0 - 1.0
    int64_t estimatedCompressedSize; // in bytes
    int64_t originalSize;            // in bytes
    std::string file;                // fileName
  };

public:
  // Initialize compression ratios
  std::map<std::string, double> COMPRESSION_RATIOS = {
      {".txt", 0.3},  // ~70% reduction
      {".csv", 0.4},  // ~60% reduction
      {".xml", 0.5},  // ~50% reduction
      {".html", 0.5}, // ~50% reduction
      {".json", 0.5}, // ~50% reduction
      {".exe", 0.7},  // ~30% reduction
      {".zip", 0.95}, // ~5% reduction (already compressed)
      {".jpg", 0.98}, // ~2% reduction
      {".png", 0.98}, // ~2% reduction
      {".mp3", 0.99}, // ~1% reduction
      {".mp4", 0.99}, // ~1% reduction
      {"other", 0.6}  // Default assumption
  };

  // Constructor
  CompressionEstimator(const std::string &filePath, int sampleSize = 1024);

  // estimate file compression size
  CompressionInfo estimateCompression();

private:
  double estimateEntropy();

private:
  std::string filePath;
  int sampleSize;
};

#endif /* COMPRESSION_ESTIMATOR_H */