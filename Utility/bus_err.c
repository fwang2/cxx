/* bus error
 * caused by misaligned read or write
 *
 * not reproducible with current gcc on x86, alas
 * but on sparc, .... it seems will
 */
int main()
{
    union {
        char a[10];
        int i;
    } u;

    int *p = (int *) &(u.a[1]);
    *p = 17;

    return 0;
}
