// demo: basic AIO setup
// without using glibc wrapper
//
// also demo: io_setup(128, ...)
// which means, under this particular context, we can send 128 requests


#ifndef _GNU_SOURCE
#define _GNU_SOURCE         // syscall() is not POSIX
#endif

#include <stdio.h>          // for perror()
#include <unistd.h>         // for syscall()
#include <sys/syscall.h>    // for __NR_* definitions
#include <linux/aio_abi.h>  // for AIO types and constants

inline int io_setup(unsigned nr, aio_context_t *ctxp)
{
    return syscall(__NR_io_setup, nr, ctxp);
}

inline int io_destroy(aio_context_t ctx)
{
    return syscall(__NR_io_destroy, ctx);
}

int main()
{
    aio_context_t ctx = 0;
    int ret = io_setup(128, &ctx);

    if (ret < 0) {
        perror("io_setup error");
        return -1;

    }

    ret = io_destroy(ctx);
    if (ret < 0) {
        perror("io_destroy error");
        return -1;
    }
    return 0;
}
