
# Linux malloc hook issue

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