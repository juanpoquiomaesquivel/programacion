#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdarg.h>

// https://youtu.be/3iX9a_l9W9Y
// https://youtu.be/S-ak715zIIE
int print(const char *format, ...)
{
    va_list args;
    int done;

    va_start (args, format);
    done = vfprintf (stdout, format, args);
    va_end (args);

    return done;
}

int main(int argc, char const *argv[])
{
    print("%d %d", 1, 2, 3);

    return 0;
}
