#ifndef LEAF_NAME
#define LEAF_NAME compareBytes
#endif

int LEAF_NAME(const unsigned char *first, const unsigned char *second,
              unsigned int length) {
    if (length != 0) {
        do {
            register int firstByte asm("$2") = *first;
            register int secondByte asm("$3") = *second;

            asm volatile ("" : "=r" (firstByte), "=r" (secondByte) :
                          "0" (firstByte), "1" (secondByte));
            if (firstByte != secondByte) {
                return firstByte - secondByte;
            }
            first++;
            length--;
            second++;
        } while (length != 0);
    }
    return 0;
}
