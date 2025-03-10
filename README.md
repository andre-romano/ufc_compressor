
# Universal File Compressor (UFC)

An automatic file compressor and optimizer written in C++.

## Features

- **Automatic file detection**: Automatically detects file types and analyzes its entropy and suitability for compression (i.e., estimated compression ratio).
- **Automatic compression algorithm choice**: Chooses the best compression algorithm for a given file type (e.g., 7Zip, RAR, ZIP, BZ2, etc).
- **Automatic optimization (for supported file types)**: Performs optimization on compressible file types (e.g., PDF, JPG, PNG, etc).
- **Lossless and lossy compression support**: Capable of using both strategies, according to the users' provided configuration (Default: lossless compression).

## Usage

Check help using command option `-h`, `--help`, `/h` or `/?`

## Supported platforms

- Windows 10 (Windows 11 might work - not tested)
- Linux (not tested)

## Releases / Installation

Check [GitHub Releases](https://github.com/andre-romano/ufc_compressor/releases) page.

## Build Dependencies

To build this project, you will need the most current stable versions of:
- Python 3 (for Conan dependency manager)
- [``Clang-MinGW-64``](https://www.mingw-w64.org/downloads/) or Clang-Linux compiler
- [`CMake`](https://cmake.org/download/) build system
- [`Ninja`](https://github.com/ninja-build/ninja/releases/) build tool 
   
Compiler must support at least `c++17` standard.
> Other compilers such as [Clang-LLVM-WinSDK](https://github.com/llvm/llvm-project/releases) (requires Windows SDK to work), [GCC-MinGW-64]() (has slow compilation) might work as well.

## Building

Run the CMD script:

```batch
call ./install_dependencies.bat
call ./config.bat
call ./build.bat
```

## Contributing

We welcome contributions! If you'd like to contribute, please fork the repository and submit a pull request.

## License and Copyright

Copyright (C) 2025 - Andre Luiz Romano Madureira

This project is licensed under the Apache License 2.0.  

For more details, see the full license text (see ``LICENSE`` file).
