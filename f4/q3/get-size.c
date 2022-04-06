#include <sys/stat.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <pwd.h>

char *get_user(unsigned uid) {
    struct passwd *pws;
    pws = getpwuid(uid);
    return pws->pw_name;
}

int main(int argc, char* argv[]) {
    struct stat info;

    int total_bytes = 0, total_disk_blocks = 0;
    int file_bytes, file_disk_blocks;

    struct     tm  ts;

    if (argc < 2) {
        fprintf(stderr, "usage: %s file\n", argv[0]);
        return EXIT_FAILURE;
    }

    for (int i = 1; i < argc; ++i) {
        if (lstat(argv[1], &info) == -1) {
            fprintf(stderr, "fsize: Can’t stat %s\n", argv[1]);
            return EXIT_FAILURE;
        }

        file_bytes = (int)info.st_size;
        file_disk_blocks = (int)info.st_blocks;

        char buf[80];

        ts = *localtime(&info.st_mtime);
        strftime(buf, sizeof(buf), "%c", &ts);

        printf("%s Size: %d bytes\nDisk_blocks: %d\nUser Owner: %s\nLast Modification: %s\n", argv[1], file_bytes, file_disk_blocks, get_user(info.st_uid), buf);

        total_bytes += file_bytes;
        total_disk_blocks += file_disk_blocks;
    }

    return EXIT_SUCCESS;
}