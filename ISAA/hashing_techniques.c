#include <stdio.h>

unsigned long fnv_hash(const char *data) {
    unsigned long hash = 14695981039346656037UL;
    const unsigned char *ptr = (const unsigned char *)data;
    while (*ptr != '\0') {
        hash ^= *ptr++;
        hash *= 1099511628211UL;
    }
    return hash;
}
int main() {
    const char *input = "Hello, world!";
    unsigned long hash = fnv_hash(input);

    printf("Input: %s\n", input);
    printf("FNV Hash: %lu\n", hash);

    return 0;
}