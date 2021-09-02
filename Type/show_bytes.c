#include <stdio.h>
typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, int len, char * prefix)
{
    printf("%s\t", prefix);
    for (int i=0; i < len; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}

void show_int(int x)
{
    show_bytes((byte_pointer) &x, sizeof(int), "int");
}

void show_long(long x)
{
    show_bytes((byte_pointer) &x, sizeof(long), "long");
}

void show_double(double x)
{
    show_bytes((byte_pointer) &x, sizeof(double), "double");
}

void show_float(float x)
{
    show_bytes((byte_pointer) &x, sizeof(float), "float");
}

void show_pointer(void *x)
{
    show_bytes((byte_pointer) &x, sizeof(void *), "void*");
}


void test_show_bytes(int val)
{
    int ival = val;
    float fval = (float) ival;
    int *pval = &val;
    show_int(ival);
    show_long(ival);
    show_double(ival);
    show_float(fval);
    show_pointer(pval);
}

int main(int argc, char* argv[])
{
    int val = 12345;
    if (argc > 1) {
        if (argv[1][0] == '0' && argv[1][1] == 'x')
            sscanf(argv[1]+2, "%x", &val);
        else
            sscanf(argv[1], "%d", &val);
        printf("Displaying bytes according to type:\n\n");
        test_show_bytes(val);
    } else {

        printf("give an integer or hex as argument\n");
    }

    return 0;

}


