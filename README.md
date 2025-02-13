
# Multi-Process Project (aqrabawi.1)

---

## Quick Start

1. **Download or Clone the Project**

   Clone the repository using:
   ```bash
   git clone https://github.com/Jadaqrabawi/aqrabawi.1.git
   ```
   Or download and extract the project archive.

2. **Navigate to the Project Directory**
   ```bash
   cd aqrabawi.1
   ```

3. **Clean the Project (Optional)**
   ```bash
   make clean
   ```

4. **Compile the Project**
   ```bash
   make
   ```

5. **Run the Project**
   ```bash
   ./oss -n 5 -s 3 -t 7
   ```

---

## Overview

This project assignment helps to become familiar with the Linux environment, process management, and the compilation/linking process. It consists of two executables:

- **oss**: The parent process that launches multiple child (user) processes based on specified command-line parameters.
- **user**: The child process that runs a loop, printing its process ID (PID), its parent’s PID (PPID), and the current iteration number, with a one-second pause between iterations.

> **Note:** The `user` executable is typically invoked by `oss` and is only run directly for testing purposes.

---

## Detailed Instructions

### Compilation

1. **Open a Terminal**  
   Navigate to your project directory:
   ```bash
   cd aqrabawi.1
   ```

2. **Compile the Project**  
   Run the following command to compile both the `oss` and `user` executables using the provided Makefile:
   ```bash
   make
   ```

### Running the Project

#### Testing the `user` Executable Directly

For testing purposes, you can run the `user` executable directly:
```bash
./user 5
```
This will execute the `user` process with 5 iterations.

#### Running the `oss` Executable

The `oss` executable launches the `user` process with specified command-line options. For example, to launch 5 user processes with a maximum of 3 processes running simultaneously and 7 iterations per process:
```bash
./oss -n 5 -s 3 -t 7
```

### Cleaning Up

To remove all compiled object files and executables, run:
```bash
make clean
```

---

## Additional Information

- **Version Control**  
  This project is managed using Git. To access the repository:
  ```bash
  git clone https://github.com/Jadaqrabawi/aqrabawi.1.git
  ```

- **Project Purpose**  
  This project serves as an introduction to process management in Linux. It demonstrates the use of system calls such as `fork()`, `exec()`, and `wait()`, and reinforces the steps involved in compiling and linking programs using a Makefile.

- **Usage Note**  
  The `user` executable is designed to be invoked by `oss`. Running `user` directly is recommended only for testing and debugging.

---
