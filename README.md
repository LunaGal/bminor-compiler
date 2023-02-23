# B-Minor Compiler

B-Minor is a simple programming language specified in the book Introduction to Compilers and Language design by Douglas Thain. I will create a scanner to correctly tokenize B Minor. Then, I will write a parser to process tokens and generate an Abstract Syntax Tree to represent the structure of a B Minor program and check that it is syntactically valid. If time permits, I will write semantic routines to process the AST and write LLVM-IR that can be compiled to source files using the LLVM toolchain.

This repository will contain flex and bison files to generate the scanner and parser, together with makefiles to automatically build those tools. Additionally, it will contain .c files to act as a driver for the various components for easy command line interaction.
