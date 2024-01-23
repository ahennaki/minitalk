# Minitalk

The Minitalk project is a client-server communication program implemented using UNIX signals. It allows the client to send a string to the server, which then displays the received string.

## Table of Contents

- [Foreword](#foreword)
- [Common Instructions](#common-instructions)
- [Project Instructions](#project-instructions)
- [Mandatory Part](#mandatory-part)
- [Bonus Part](#bonus-part)

## Foreword

The Minitalk project focuses on implementing a client-server communication program using UNIX signals. It uses the `cis-3-Hexen-1-ol` (also known as leaf alcohol) as a reference.

## Common Instructions

- The project must be written in C.
- The code must comply with the Norm.
- The program should not have unexpected errors (e.g., segmentation fault, bus error) apart from undefined behaviors.
- Memory allocated using `malloc` must be freed appropriately to avoid leaks.
- If required, a Makefile should be included, following the provided format.
- The Makefile should compile the program with the flags `-Wall`, `-Wextra`, and `-Werror`.
- The project should be submitted to the assigned Git repository.

## Project Instructions

- The client and server executables should be named `client` and `server`, respectively.
- A Makefile should be included to compile the source files without relinking.
- The program can use the provided `libft` library.
- Error handling should be thorough, and the program should not quit unexpectedly.
- Memory leaks should be avoided.

## Mandatory Part

- The server should be started first and print its PID after launching.
- The client should take two parameters: the server PID and the string to send.
- The client should send the string to the server.
- Once the string is received, the server should print it.
- The server should display the string quickly, without significant delays.

## Bonus Part

- The server should acknowledge every received message by sending a signal back to the client.
- Unicode characters should be supported.
