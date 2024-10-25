#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>
#include <time.h>

unsigned int sleep(unsigned int seconds)
{
    struct timespec requested_time;
    struct timespec remaining;
    requested_time.tv_sec = seconds;
    requested_time.tv_nsec = 0;

    int ret = nanosleep(&requested_time, &remaining);

    if (ret == -1)
        requested_time = remaining;

    return 0;
}
