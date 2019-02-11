#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

void bbname() {
    char hostname[1024];
    hostname[1023]= '\0';
    gethostname(hostname, 1023);
    printf("Hostname: %s\n", hostname);
}

int main(void) {

    bbname();

}
