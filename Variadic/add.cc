#include <cstdarg>
#include <cstdio>

int add(int args, ...)
{
    va_list ap;
    va_start(ap, args);
    // process: go through arg list and process each
    int i = 0, sum = 0;
    for(i = 0; i < args; i++)
        sum += va_arg(ap, int);
    va_end(ap);
    return sum;
}

int main()
{
    printf("%d\n", add(3, 1, 2, 3));
    return 0;
}