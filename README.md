# B-Minor Compiler

B-Minor is a simple programming language specified in the book Introduction to Compilers and Language design by Douglas Thain. I will create a scanner to correctly tokenize B Minor. Then, I will write a parser to process tokens and generate an Abstract Syntax Tree to represent the structure of a B Minor program and check that it is syntactically valid. If time permits, I will write semantic routines to process the AST and write LLVM-IR that can be compiled to source files using the LLVM toolchain.

This repository contains flex and bison files to generate the scanner and parser, together with makefiles to automatically build those tools. Additionally, it will contain .c files to act as a driver for the various components for easy command line interaction.

# Credits

The headers under "typdefs", the headers under "Constructor Headers", and the decl_create function are taken from Introduction to Compilers and Language Design by Douglas Thain, with slight modifications. Additionally, lines 17-22 of parser_driver.c are from Introduction to Compilers and Language Design by Douglas Thain. All other code is my own, with guidance and inspiration sources in my bibliography.

# Functionality

Use `make scanner_driver` to create a scanner driver. Invoke using `./scanner_driver [file1].bmr`. It will print a list of B Minor tokens found in `[file1]`.

Use `make parser_driver` to create a parser driver. Invoke using `./parser_driver [file1].bmr`. It will validate `[file1].bmr` and say whether it has correct B Minor syntax. If it successfully validates it, it will print an abstract syntax tree. Currently, it can only handle a very restricted subset of the language.