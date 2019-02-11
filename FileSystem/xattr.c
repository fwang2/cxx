#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/xattr.h>

#define XATTR_SIZE 10000

int
main(int argc, char** argv)
{
    char list[XATTR_SIZE], value[XATTR_SIZE];
    ssize_t listLen, valueLen;
    int ns, k;
    ;

    listLen = listxattr(argv[1], list, XATTR_SIZE);

    if (listLen == -1) {
        perror("listxattr");
        exit(-1);
    } else {
        printf("listLen = %d\n", listLen);
    }

    for (ns = 0; ns < listLen; ns += strlen(&list[ns]) + 1) {
        printf("    name=%s; ", &list[ns]);

        if (!strcmp("lustre.lov;", &list[ns]))
            continue;

        valueLen = getxattr(argv[1], &list[ns], value, XATTR_SIZE);

        if (valueLen == -1) {
            perror("getxattr");
            exit(-1);
        } else {
            printf("valueLen = %d\n", valueLen);

            printf("\n");

            for (k = 0; k < valueLen; k++)
                printf("%02x ", (unsigned int)value[k]);
        }

        printf("\n");
    }

    return 0;
}
