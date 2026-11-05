/* Four GSM RPE coefficient words between synthesis stages. */
typedef unsigned short u16;

const u16 gsmRpeCoefficients[4] __attribute__((section(".rodata"))) = {
    0xC7D7, 0xE3E7, 0xF1F3, 0xF5F7,
};
