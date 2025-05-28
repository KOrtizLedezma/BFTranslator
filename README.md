<h1 align="center">Brainfuck to C Translator</h1>

<p align="center">
  <img src="https://img.shields.io/github/languages/top/KOrtizLedezma/BFTranslator" alt="Top Language" />
  <img src="https://img.shields.io/github/last-commit/KOrtizLedezma/BFTranslator" alt="Last Commit" />
  <img src="https://img.shields.io/github/license/KOrtizLedezma/BFTranslator" alt="License" />
</p>


## Overview

This tool takes Brainfuck code — either from a file or direct terminal input — and:

1. Cleans it of useless instructions and invalid characters
2. Verifies bracket balance (`[`, `]`)
3. Translates the logic into readable, structured C code
4. Compiles the C code into a native executable
5. Runs the compiled program automatically

## Getting Started

### Prerequisites

- C++17 compiler (e.g., `g++`)
- [CMake](https://cmake.org/download/)
- [`gcc`](https://gcc.gnu.org/) for compiling the generated C code

### Build Instructions
```bash
  git clone https://github.com/KOrtizLedezma/BFTranslator.git
  cd BFTranslator
  mkdir build && cd build
  cmake ..
  make
```
This builds the brainfuck_translator binary.

## Usage

### Translate from a file
```bash
  ./brainfuck_translator path/to/program.bf
``` 
### Translate from terminal input
```bash
  ./brainfuck_translator
```

## Inspiration
This project was inspired by a Codewars kata that involved optimizing and cleaning Brainfuck code. The idea was expanded into a full-featured C translator with auto-compilation and execution.


## Author
Kenet Ortiz
