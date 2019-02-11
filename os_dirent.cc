#include <dirent.h>
#include <unistd.h>
#include <iostream>

int main(void) {
    DIR * dirp;
    struct dirent *dp;

    dirp = opendir("/tmp/vfs/");

    if (dp == NULL) {
        std::cerr << "opendir()" << std::endl;
        return -1;
    }

    int cnt = 0;

    for (;;) {
        dp = readdir(dirp);
        if (dp == NULL) break;
        cnt++;
    }

    std::cout << "Number = " << cnt << std::endl;
    return 0;
}

