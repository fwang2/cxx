#include <pthread.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    pthread_t thread = NULL;
    int status;
    status = pthread_join(thread, NULL);
    if (status !=0 ) {
        fprintf(stderr, "error %d: %s\n", status, strerror(status));
    }
}