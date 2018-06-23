#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

static uint32_t revbits(uint32_t n)
{
    n = ((n >> 1) & 0x55555555) | ((n << 1) & 0xaaaaaaaa);
    n = ((n >> 2) & 0x33333333) | ((n << 2) & 0xcccccccc);
    n = ((n >> 4) & 0x0f0f0f0f) | ((n << 4) & 0xf0f0f0f0);
    n = ((n >> 8) & 0x00ff00ff) | ((n << 8) & 0xff00ff00);
    n = ((n >> 16) & 0x0000ffff) | ((n << 16) & 0xffff0000);
    return n;
}

int main(int argc, char *argv[])
{
    int i;
    uint32_t n, r;

    if (1 == argc) {
        printf("usage: %s [INTS...]\n", argv[0]);
        puts("Reverse the bits in 32-bit integers.");
        return 0;
    }

    for (i = 1; i < argc; i++) {
        n = (uint32_t) strtoul(argv[i], NULL, 0);
        r = revbits(n);
        printf("%lu 0x%lx\t%lu 0x%lx\n", (unsigned long int) n,
               (unsigned long int) n, (unsigned long int) r,
               (unsigned long int) r);
    }

    return 0;
}
