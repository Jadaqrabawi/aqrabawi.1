# Makefile
# Author: aqrabwi, 13/02/2025
# Description: Compiles two executables (oss and user) from their respective source files.

# Set the compiler to gcc.
CC      = gcc

# Compiler flags: -Wall enables all warnings, -g includes debugging information.
CFLAGS  = -Wall -g

# List of target executables to be built.
TARGETS = oss user

# The default target "all" builds both oss and user executables.
all: $(TARGETS)