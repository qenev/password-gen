# Password Generator

A lightweight CLI password generator written in C.

## Features
- Configurable length
- Toggle inclusion of uppercase, lowercase, digits, symbols
- Cryptographically seeded via `time()`

## Build
```bash
make
```

## Usage
```bash
./passgen -l 16 -s
```
