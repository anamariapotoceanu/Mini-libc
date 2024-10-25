
#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>
#include <string.h>

int puts(const char *s)
{
    int ret = write(__NR_write, s, strlen(s));
    write(__NR_write, "\n", 1);
    return ret;
}
