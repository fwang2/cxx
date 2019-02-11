#include <bzlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#define FILE_MODE (S_IRUSR | S_IWUSR)
#define BLOCKSIZE (900000)
#define BUFSIZE (909600)

ssize_t
do_read(int fd, void* buf, size_t count) {
    ssize_t bytesRemaining = count;
    ssize_t nbytes = 0;
    char* pbuf = (char*)buf;
    while ((bytesRemaining > 0) &&
           (nbytes = read(fd, pbuf, bytesRemaining)) > 0) {
        bytesRemaining -= nbytes;
        pbuf += nbytes;
    }

    if (nbytes < 0) {
        perror("do_read()");
        ;
        return nbytes;
    }

    return (count - bytesRemaining);
}

ssize_t
do_write(int fd, const void* buf, size_t count) {
    ssize_t bytesRemaining = count;
    ssize_t nbytes = 0;
    const char* pbuf = (const char*)buf;
    while ((bytesRemaining > 0) &&
           ((nbytes = write(fd, pbuf, bytesRemaining)) > 0)) {
        bytesRemaining -= nbytes;
        pbuf += nbytes;
    }

    if (nbytes < 0) {
        perror("do_write()");
        return nbytes;
    }

    return (count - bytesRemaining);
}

int
main(int argc, char** argv) {
    struct stat sb;
    size_t blocksize = 9 * 100000;
    unsigned int insize = 0;
    unsigned int outsize = 0;
    ssize_t ret;
    char in[BLOCKSIZE];
    char out[BUFSIZE];

    if (argc != 2) {
        fprintf(stderr, "must provide a input file\n");
        exit(EXIT_FAILURE);
    }

    ret = stat(argv[1], &sb);

    if (ret) {
        perror("stat");
    }

    size_t bytesleft = sb.st_size;

    int infd = open(argv[1], O_RDONLY);
    int outfd = open("out.bz2", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (outfd < 0) {
        fprintf(stderr, "error creating output file\n");
        exit(EXIT_FAILURE);
    }

    printf("input filesize = %ld\n", bytesleft);

    while (bytesleft > 0) {
        // read data
        if (bytesleft > blocksize)
            insize = blocksize;
        else
            insize = bytesleft;

        ret = do_read(infd, in, insize);
        if (ret == 0)
            break;

        bytesleft -= ret;

        outsize = BUFSIZE;

        // compress data
        ret = BZ2_bzBuffToBuffCompress(out, &outsize, in, insize, 9, 0, 30);

        if (ret != BZ_OK) {
            switch (ret) {
                case BZ_CONFIG_ERROR:
                    perror("BZ_CONFIG_ERROR");
                    break;
                case BZ_PARAM_ERROR:
                    perror("BZ_PARAM_ERROR");
                    break;
                case BZ_MEM_ERROR:
                    perror("BZ_MEM_ERROR");
                    break;
                case BZ_OUTBUFF_FULL:
                    perror("BZ_OUTBUF_FULL");
                    break;
                default:
                    perror("Unknown compression error");
            }

            close(infd);
            exit(EXIT_FAILURE);
        }

        // write data to output
        ret = do_write(outfd, out, outsize);
    }

    close(infd);
    close(outfd);
    return 0;
}
