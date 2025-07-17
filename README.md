# Introduce

This project is used to test tinycc lib for run C code as a script.

# Build

```bash
./build.sh
```

# Usage

```bash
cd products
./bin/tcc_test

output:
    3 + 5 = 8
```

# Issues

## Linux malloc hook issue

Modify the tinycc/libbcheck.c file

```c
#if defined(__FreeBSD__) \
 || defined(__FreeBSD_kernel__) \
 || defined(__DragonFly__) \
 || defined(__OpenBSD__) \
 || defined(__NetBSD__) \
 || defined(__dietlibc__) \
 || defined(_WIN32) \
 || defined(__linux__)
//#warning Bound checking does not support malloc (etc.) in this environment.
#undef CONFIG_TCC_MALLOC_HOOKS
#undef HAVE_MEMALIGN
#endif
```

Then run ```./build.sh``` to build this project.