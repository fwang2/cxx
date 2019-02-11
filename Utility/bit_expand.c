#include <stdio.h>
#include "t_lib.h"

void show_float2(float val)
{
    show_bytes((byte_pointer) &val, sizeof(float));
}

void test_show_bytes(int val)
{
    int ival = val;
    float fval = (float) ival;
    int *pval = &val;
    show_int(ival);
    show_float2(fval);
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
        printf("calling show_bytes()\n");
        test_show_bytes(val);
    } else {

        printf("give an integer or hex as argument\n");
    }

    return 0;

}


