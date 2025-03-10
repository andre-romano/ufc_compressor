
# Auto File Compressor

An automatic file compressor and optimizer written in C++.

## Features

- **Automatic file detection**: Detects file types and chooses a suitable compression algorithm for it.
- **Automatic compression algorithm choice**: Chooses the best compression algorithm for a given file type.
- **Automatic optimization (for supported file types)**: Performs optimization on compressible file types (e.g., PDF, JPG, PNG, etc).

## Usage

Check help using command option `-h`, `--help`, `/h` or `/?`

## Building (CLI version)

To build this project, you will need the most current version of ``Clang`` compiler, `CMake` and `Ninja` build systems, as well as ``Windows SDK``. They must support at least `c++17` standard.

Run the CMD script:

```batch
call ./config.bat
call ./build.bat
```

## Contributing

We welcome contributions! If you'd like to contribute, please fork the repository and submit a pull request.

## License and Copyright

Copyright (C) 2025 - Andre Luiz Romano Madureira

This project is licensed under the Apache License 2.0.  

For more details, see the full license text (see ``LICENSE``).
