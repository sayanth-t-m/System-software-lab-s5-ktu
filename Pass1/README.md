# Two-Pass Assembler

A simple two-pass assembler written in C. This assembler reads assembly code from an `input.txt` file, processes it using opcode information from `opcode.txt`, and generates an intermediate representation in `out1.txt` along with a symbol table in `sym1.txt`.

## Table of Contents

- [Files](#files)
- [Usage](#usage)
  - [Input Files](#input-files)
  - [Run the Assembler](#run-the-assembler)
  - [Output](#output)
    - [Intermediate Representation](#intermediate-representation)
    - [Symbol Table](#symbol-table)
- [Example](#example)
- [Linux Run Command](#linux-run-command)
- [License](#license)

## Files

- `input.txt`: Contains the assembly code to be assembled.
- `opcode.txt`: Contains opcode information for the assembler.
- `out1.txt`: Output file with the intermediate representation.
- `sym1.txt`: Output file with the symbol table.

## Usage

### Input Files

1. Place your assembly code in `input.txt`.
2. Define opcodes in `opcode.txt`.

### Run the Assembler


- **File:** `out1.txt`

   This file contains the intermediate representation of the assembled code.

#### Symbol Table

- **File:** `sym1.txt`

  This file contains the symbol table generated during the assembly process.



