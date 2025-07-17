#include <stdio.h>
#include "libtcc.h"

int main(int argc, char **argv) {
    TCCState *s = tcc_new();
    int ret = tcc_set_output_type(s, TCC_OUTPUT_MEMORY);
    ret = tcc_compile_string(s, "int add(int a, int b) { return a + b; }");
    ret = tcc_relocate(s, TCC_RELOCATE_AUTO);

    int (*func)(int, int) = tcc_get_symbol(s, "add");
    if (func) {
        printf("3 + 5 = %d\n", func(3, 5)); // 输出: 8
    }
    tcc_delete(s);
    return 0;
}