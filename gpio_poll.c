#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>
#include <poll.h>

int main(int argc, char *argv[])
{
    char path[256];
    struct pollfd pfd = {};
    int fd, N;
    char val = 0;

    if (argc != 2) {
         fprintf(stderr, "%s N_gpio\n", argv[0]);

         return -1;
    }

    N = atoi(argv[1]);
    snprintf(path, sizeof(path), "/sys/class/gpio/gpio%d/value", N);

    if ((fd = open(path, O_RDONLY)) < 0)
    {
       fprintf(stderr, "Failed to open gpio #%d\n", N);

       return -1;
    }

    pfd.fd = fd;
    pfd.events = POLLPRI;

    pread(fd, &val, 1, 0);
    printf("value: %c\n", val);

    while (1) {
        poll(&pfd, 1, -1);

        printf("value: %c -> ", val);
        pread(fd, &val, 1, 0);
        printf("%c\n", val);
    }

    return 0;
}
