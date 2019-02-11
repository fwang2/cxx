#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
static void sigHandler(int sig)
{
    printf("Ouch!\n");
}

int main(int argc, char * argv[])
{
    int j;

    if (signal(SIGINT, sigHandler) == SIG_ERR)
        exit(1);
    for (j = 0; ; j++) {
        printf("%d\n", j);
        sleep(3);
    }
    std::string s = nullptr;
}
