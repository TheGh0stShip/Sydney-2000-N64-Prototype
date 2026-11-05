/* Runtime display state at 0x800F2720, using a fixed N64 address token. */
void func_800B4794(unsigned int value) {
    register volatile unsigned int *statePage __asm__("$2") =
        (volatile unsigned int *)0x800F0000;
    __asm__ volatile ("" : "=r"(statePage) : "0"(statePage));
    statePage[0x2720 / 4] = value;
}
