/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800ADC1C\n.ent func_800ADC1C\n"
    "func_800ADC1C:\n"
    "sll $2,$16,0x1\n"
    "addu $2,$2,$16\n"
    "sll $2,$2,0x2\n"
    "addiu $2,$2,2576\n"
    "addu $2,$3,$2\n"
    "lbu $6,0($2)\n"
    "lbu $4,1($2)\n"
    ".end func_800ADC1C\n.set at\n.set reorder\n");
