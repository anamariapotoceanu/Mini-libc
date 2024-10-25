# Mini-libc

## Objectives
- Understand the structure and functionalities provided by the standard C library
- Familiarize with the Linux syscall interface
- Deepen understanding of string and memory management functions
- Explore the support provided by the standard C library for low-level I/O operations

## Statement
The objective of this project is to build a minimalistic implementation of the [standard C library](https://en.wikipedia.org/wiki/C_standard_library) for Linux systems, named `mini-libc`. This library is designed to be a minimal, functional replacement for the system’s standard C library (typically glibc on Linux), supporting string management, basic memory handling, and POSIX file I/O.

The implementation must be freestanding, meaning it cannot rely on any external library calls and will instead operate using the system call interface available on Linux for the x86_64 architecture. This freestanding approach requires implementing any necessary functions that are typically part of the libc. Once implemented, these functions may be reused within other parts of `mini-libc`.

## API and Implementation Tasks
The API for `mini-libc` includes a subset of the standard C library functions. The following headers are of particular interest:

1. `<string.h>`: Defines string-handling functions. Implement:
   - `strcpy()`, `strcat()`, `strlen()`, `strncpy()`, `strncat()`
   - `strcmp()`, `strncmp()`, `strstr()`, `strrstr()`
   - `memcpy()`, `memset()`, `memmove()`, `memcmp()`

2. `<stdio.h>`: Defines printing and I/O functions. Implement:
   - `puts()`

3. `<unistd.h>`, `<sys/fcntl.h>`, `<sys/stat.h>`: Define I/O primitives. Implement:
   - `open()`, `close()`, `lseek()`
   - `stat()`, `fstat()`
   - `truncate()`, `ftruncate()`

4. `<time.h>`: For time functions, implement:
   - `nanosleep()`, `sleep()`

5. `<stdlib.h>`, `<sys/mman.h>`: Define memory allocation functions. Implement:
   - `malloc()`, `free()`, `calloc()`, `realloc()`, `realloc_array()`
   - `mmap()`, `mremap()`, `munmap()`

6. `<errno.h>`: Implement error handling via `errno`, an integer variable that indicates errors during system calls or library functions.

### Additional Requirements
- Add the necessary header `<time.h>`.
- Declare and implement the `puts()`, `nanosleep()`, and `sleep()` functions.
- Update the `libc` Makefile to build source files that implement `puts()`, `nanosleep()`, and `sleep()`.
