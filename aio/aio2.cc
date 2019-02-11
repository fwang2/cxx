// demo
//
//
#ifndef _GNU_SOURCE
#define _GNU_SOURCE             // syscall() is not POSIX
#endif


#include <stdio.h>
#include <unistd.h>             // for syscall()
#include <sys/syscall.h>        // for __NR_* definitions
#include <linux/aio_abi.h>      // for AIO types and constants
#include <fcntl.h>              // for O_RDWR
#include <string.h>             // memset()
#include <inttypes.h>           // uint64_t

inline int io_setup(unsigned nr, aio_context_t *ctxp)
{
    return syscall(__NR_io_setup, nr, ctxp);
}

inline int io_destroy(aio_context_t ctx)
{
    return syscall(__NR_io_destroy, ctx);
}

inline int io_submit(aio_context_t ctx, long nr, struct iocb **iocbpp)
{
    return syscall(__NR_io_submit, ctx, nr, iocbpp);
}

inline int io_getevents(aio_context_t ctx, long min_nr, long max_nr,
        struct io_event *events, struct timespec *timeout)
{
    return syscall(__NR_io_getevents, ctx, min_nr, max_nr, events, timeout);
}

int main()
{
    struct iocb cb;
    struct iocb *cbs[1];
    char data[4096];
    struct io_event events[1];

    int fd = open("/tmp/testfile", O_RDWR | O_CREAT);
    if (fd < 0) {
        perror("open error");
        return -1;
    }

    aio_context_t ctx = 0;
    int ret = io_setup(128, &ctx);
    if (ret < 0) {
        perror("io_setup error");
        return -1;
    }

    // setup I/O control block
    // (1) file descriptor (2) commands

    memset(&cb, 0, sizeof(cb));
    cb.aio_fildes = fd;
    cb.aio_lio_opcode = IOCB_CMD_PWRITE;    // PREAD PWRITE FSYNC FDSYNC PREADV PWRITEV

    // command specific options

    cb.aio_buf = (uint64_t) data;
    cb.aio_offset = 0;                      // this is absolute offset in a file
    cb.aio_nbytes = 4096;

    cbs[0] = &cb;

    ret = io_submit(ctx, 1, cbs);           // aio context, size of the array, array itself
                                            // ret == number of iocbs
                                            // submitted
                                            //
                                            //
                                            // kernel process iocb one by one
                                            // until it fails. In that case,
                                            // it returns the index of the
                                            // failure point. However, there
                                            // is no failure reasons given.
                                            //
                                            // if ret < 0, it means some error
                                            // happens even before io_submit()
                                            // started to iterate over iocbs
                                            // in the array. "errno" is set in
                                            // this case, and we can perror()
                                            // it out for examiniation.
                                            //
                                            //

    if (ret != 1) {
        if (ret < 0)
            perror("io_submit error");
        else
            fprintf(stderr, "could not submit IOs");
        return -1;
    }

    // for every completed I/O requests (success or not), kernel creates a
    // io_event structure. The list of io_events is obtained by io_getevent()
    // call.
    // (1) AIO context to retrieve events
    //
    // (2) minimal number of events one wants to get, if less than this number
    // of iocbs are currently completed, io_getevents() will block until
    // enough events appears.
    //
    // (3) maximal number of events one wants to get.
    //
    // (4) a buffer kernel will load the events in
    //
    // (5) if not enough events are available, and we don't want to wait
    // forever. One can specify a deadline as the last argument. NULL means to
    // wait forever. or "timespec" timeout structure can be used with zero
    // seconds and zero nanoseconds to *not* to block at all.
    //
    //

    ret = io_getevents(ctx, 1, 1, events, NULL);
    printf("%d\n", ret);

    ret = io_destroy(ctx);
    if (ret < 0) {
        perror("io_destroy error");
        return -1;
    }

    return 0;
}

