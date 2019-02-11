/*
 * sizeof a function or an operator?
 *
 */
#include <stdlib.h>
int main() 
{
    int * p;
    char c = '3';

    char  *buf, *q = &c;
    /* now * p is a variable, no () needed */
     
    int N = 20 * sizeof * p;

    buf =  malloc(N);

    /* if it is a type, then () is required */

    buf = malloc(100*sizeof(int));

    /* now what does it mean? */
    /* () is needed */

    N = sizeof ((int) *q);


    return 0;
}

