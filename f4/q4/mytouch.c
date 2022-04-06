#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <utime.h>

int main(int argc, char const *argv[]) {
    
    if (argc < 2) {
        printf("usage: mytouch filename1 filename2 ...\n");
        return EXIT_FAILURE;
    }

    for (int i = 1; i < argc; ++i) {
        
        mode_t perms = (mode_t) 0;
        perms |= S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

        int fd = open(argv[i], O_CREAT, perms);

        utime(argv[i], NULL);
        close(fd);
    }

    return EXIT_SUCCESS;
}
