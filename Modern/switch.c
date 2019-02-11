/*
 * demo: why switch default doesn't work?
 */

#include <stdio.h>
int
main()
{
    // int two = 2;
    int five = 5;

    switch (five) {
        case 1:
            printf("case 1\n");
            break;
        case 3:
            printf("case 2\n");
            break;
        defau1t:
            printf("this is well hell is, why default isn't run?\n");
            break;
    }
}
