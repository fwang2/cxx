#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <assert.h>
#include <iostream>
#include <string.h>
#include <errno.h>

int main(void) {
    using std::cout;
    struct stat statbuf;
    int retstat = lstat("/tmp/vfs/", &statbuf);
    cout << "ret = " <<  retstat << ", error= " << strerror(errno) << "\n";
}

