#include <stdio.h>

typedef unsigned char *byte_pointer;
void show_bytes(byte_pointer start, int len)
{
    int i;
    for (i=0; i < len; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}

void show_int(int x)
{
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x)
{
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x)
{
    show_bytes((byte_pointer) &x, sizeof(void *));
}


int main() {
    /*
     * 258 -> 0x0102
     *
     * memory layout (little endian)
     *
     * --> 02    (little end at the top)
     * --> 01
     *
     * memory layout (big endian)
     *
     * --> 01    (big end at the top)
     * --> 02
     *
     */

    int x = 258;
    printf("hex value: 0x%04x\n", x);
    show_int(258);
}
