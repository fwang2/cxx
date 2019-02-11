#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int main() {
    struct timeval tv1, tv2;
    char * buf;
    int ret;
    int s, ms;
    unsigned int h, g4;
    /* s is for seconds
     * ms is for microseconds
     * d is for days
     */

    ret = gettimeofday(&tv1, NULL);
    if (ret)
        perror("gettimeofday");
    buf = malloc(1<<10);
    free(buf);
    ret = gettimeofday(&tv2, NULL);
    if (ret)
        perror("gettimeofday");
    
    s = tv2.tv_sec - tv1.tv_sec;
    ms = tv2.tv_usec - tv1.tv_usec;
        
    if (s!=0)
        printf("%d seconds,", s);

    printf("%d microseconds \n", ms);

    /* g4 = (1 << 31); */
    g4 = 0xFFFFFFFF;
    h = ((g4/1000000)*ms)/(60*60);

    printf("Search 4GB space will take %d hours\n", h);  
    

    return 0;
}
