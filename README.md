# Simple Shell

## Description
Simple Shell is a basic UNIX command line interpreter written in C.
It displays a prompt, reads user input, executes commands found in
the PATH, and implements a small set of built-in commands.

This project is part of the Holberton School curriculum and focuses
on understanding how shells work internally.

---

## Features
- Displays a prompt and waits for user input
- Executes commands with arguments
- Handles commands using the PATH environment variable
- Built-in commands:
  - `exit`
  - `env`
- Handles Ctrl+D (EOF)
- Error handling for invalid commands

---

## Requirements
- Allowed editors: `vi`, `vim`, `emacs`
- Compiled on Ubuntu 20.04 LTS
- Compiler: `gcc`
- Compilation flags:
  ```bash
  gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
