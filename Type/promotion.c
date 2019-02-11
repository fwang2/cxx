#include <stdio.h>

/*
 * Two's complement of a binary number is defined as the value
 * obtained by subtracting positive number from a bit-width power of two
 * 
 * OK, this is confusing. Say you have a positive number N, and n is the
 * number of bits in the representation. N* is the two-complement negative
 * number you want to find out, here is the formal definition:
 *
 * N* = 2^n - N, 
 *
 * so for 4-bit representation of -5
 * 
 * N* = 2^4 - 5 = 0b 10000 - 0b 0101 = 0b1011
 *
 * 0b denote the binary representation
 *
 * An more intuitive explanation:
 *
 * N = 4 bits, essentially, we are dividing the number space
 * one section is positive, the other section is negative
 *
 * 0 0 0 0  -> 0
 * 0 0 0 1  -> 1
 * 0 0 1 0  -> 2
 * 0 0 1 1  -> 3
 * 0 1 0 0  -> 4
 * 0 1 0 1  -> 5
 * 0 1 1 0  -> 6
 * 0 1 1 1  -> 7  (max positive)
 * 1 0 0 0  -> -8 (max negative)
 * 1 0 0 1  -> -7
 * 1 0 1 0  -> -6
 * 1 0 1 1  -> -5
 * 1 1 0 0  -> -4
 * 1 1 0 1  -> -3
 * 1 1 1 0  -> -2
 * 1 1 1 1  -> -1
 *
 * Now, say we have a number 0 1 0 1 (5), 
 * how do we obtain its negative value, which is -5?
 *
 * if we flip every bit, we got one's complement
 *
 * 0 1 0 1 -> 1 0 1 0
 *
 * if we add 1 to the result, we got two's complement
 *
 * 1 0 1 1
 *
 * above is a signed representation of negative 5
 *
 * if you flip and add 1 to a negative value like -5, you got the positive
 * value
 *
 */

int alist[] = {23,33,12,1,3,5,32,2};

#define TOTAL_ELEMENTS sizeof(alist)/sizeof(alist[0])

main() {
    int d = -1;
    unsigned int    ui = d;
    int             f1 = 0x80000001;

    int             f11 = -(1<<31)+1;

    unsigned int    f2 = 0x80000001;

    int             f3 = 0xffffffff;

    int             f4 = 0x00000000;

    /*  -1 is prompted to unsigned 
     *  and the trouble begins 
     */

    
    if ( -1 < (unsigned char) 1 )
        printf("-1 is less than (unsigned char) 1: ANSI semantics\n");
    else
        printf("-1 is NOT less than (unsigned char) 1: K&R semantics\n");


    printf("total number of array elements: %d\n", TOTAL_ELEMENTS);

    if (d < TOTAL_ELEMENTS)
        printf("hmm ... it is actually right!\n");
    else
        printf("bummer, what is wrong?\n");


    printf("signed f1=0x8000 0001 = %d\n", f1);
    printf("signed f11= -(1<<31)+1 = %d\n", f11);


    if (f1 == f11) 
        printf("ok, f1 is same as f11\n");
    else
        printf("why f1 is not -1?\n");

    printf("signed f3= 0xffff ffff= %d\n", f3);

    if ( f3 == -1) {
        printf("aha, got you, -1\n");
    }

    printf("signed f4=0x0000 0000 = %d \n", f4);

    /*
     * and this is to show how the signed int is "promoted" into unsigned int.
     * -1 is 0xFFFF FFFF in signed form
     *  to convert it to unsigned form, ignore the signed bit
     *  and you have the unsigned form 0x FFFF FFFF, which amounts to 
     *  unsigned maximum 4294967295
     */

    printf("signed to unsigned -1 = %u \n", ui);

}

