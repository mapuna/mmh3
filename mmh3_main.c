#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mmh3.h"

int main() {
    const char *key = " ";
    int len = 32, i;
    uint32_t seed = 0xaaaaaaaa;
    uint32_t out1, out2[4];
    uint64_t out3[2];
    
    mmh3_x86_32(key, strlen(key), seed, &out1);
    mmh3_x86_128(key, strlen(key), seed, out2);
    mmh3_x64_128(key, strlen(key), seed, out3);
    
    printf("mmh3 32/32: 0x%x\n", out1);
    printf("mmh3 32/128: 0x");
    for (i = 3; i >= 0; i--)
        printf("%x", out2[i]);
    printf("\n");
    printf("mmh3 64/128: 0x");
    for (i = 1; i >= 0; i--)
        printf("%zx", out3[i]);
    printf("\n");
    return 0;
}

