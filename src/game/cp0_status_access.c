#ifndef READ_NAME
#define READ_NAME readCp0Status
#endif

#ifndef WRITE_NAME
#define WRITE_NAME writeCp0Status
#endif

unsigned int READ_NAME(void) {
    unsigned int value;

    asm volatile("mfc0 %0,$12" : "=r"(value));
    return value;
}

void WRITE_NAME(unsigned int value) {
    asm volatile("mtc0 %0,$12" : : "r"(value));
}
