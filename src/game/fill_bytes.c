#ifndef LEAF_NAME
#define LEAF_NAME fillBytes
#endif

void *LEAF_NAME(void *destination, int value, unsigned int length) {
    volatile unsigned char frame[1];
    register void *result asm("$2") = destination;
    register unsigned char *current asm("$7") = result;

    asm volatile ("" : "=r" (result), "=r" (current) :
                  "0" (result), "1" (current));

    if (length != 0) {
        register unsigned int remaining asm("$3") = length - 1;
        register unsigned int finished asm("$6") = (unsigned int)-1;

        asm volatile ("" : "=r" (remaining), "=r" (finished) :
                      "0" (remaining), "1" (finished));
        do {
            *current = value;
            remaining--;
            current++;
        } while (remaining != finished);
    }
    return result;
}
