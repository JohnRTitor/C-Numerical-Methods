# Contributing to C-Numerical-Methods

Thank you for considering contributing to C-Numerical-Methods! This repository is dedicated to course assignments on Numerical Methods using the C programming language. We welcome contributions from both classmates and external contributors.

Before you start, please take a moment to review the guidelines outlined in this document to ensure a smooth and collaborative contribution process.

## Table of Contents

1. [Getting Started](#getting-started)
2. [Development Workflow](#development-workflow)
3. [Coding Standards](#coding-standards)
4. [Building and Running](#building-and-running)
5. [License](#license)

## Getting Started

GNU/Linux enviornment is preferred. However it is possible to setup C development enviornment in Windows using mingw-w64 or MSYS 2.
Install Git, GCC/Clang in the system. For debian/Ubuntu, install the `build-essential` package that bundles all the relevant packages.

1. Fork the repository to your GitHub account.
2. Clone the forked repository to your local machine:
   ```bash
   git clone https://github.com/YOUR-USERNAME/C-Numerical-Methods.git
   ```

## Development Workflow

1. Switch to the dev branch:
   ```bash
   git checkout dev
   ```

2. Make your changes, adhering to the [coding standards](#coding-standards).

3. Test your changes locally to ensure they work as expected.

4. Commit your changes:
   ```bash
   git commit -m "Your descriptive commit message"
   ```

5. Push your branch to your GitHub fork:
   ```bash
   git push
   ```

6. Open a pull request (PR) to the main repository targetting the dev branch. Be sure to reference any relevant issues.

## Coding Standards

- C source file names must be in kebab case: hello-world.c

- Follow the standard naming conventions for C programming:
  - Trivial variables: `i`, `n`, `c`, etc.
  - Local variables: camelCase, be descriptive.
  - Global variables: `g_camelCase`.
  - Macros and constants in caps: `MAX_BUFFER_SIZE`, `TRACKING_ID_PREFIX`.
  - Pointer variables: `p_var` for local, `gp_var` for global, `fp_var` for far pointers.
  - Functions: camelCase.

- Avoid the use of global variables whenever possible.

## Building and Running

To compile the code, you can use a C compiler such as Clang or GCC. The repository includes a Makefile for convenience. Use the following commands:

- To compile a debug binary from name-c-file.c source file:
  ```bash
  make name-c-file
  ```

The debug build will be titled debug.out/debug.exe.

- To generate a release binary:
  ```bash
  make release-name-c-file
  ```

The release build will create an optimized binary with the same name.

To run the compiled binary:
  ```
  ./debug.out
  ```
  or for release builds
  ```
  ./release-file-name.out
  ```

Note: to use `make` you need to have make installed.

## License

By contributing to this project, you agree that your contributions will be licensed under the [Apache License 2.0](LICENSE).

Happy coding!
