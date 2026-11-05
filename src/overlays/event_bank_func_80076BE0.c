/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076BE0\n.ent func_80076BE0\n"
    "func_80076BE0:\n"
    "ori $16,$16,0xa2c\n"
    "addu $16,$18,$16\n"
    "jal func_800ADC1C\n"
    "move $4,$16\n"
    "lw $2,180($16)\n"
    "lh $4,24($2)\n"
    "lw $2,28($2)\n"
    "jalr $2\n"
    "addu $4,$16,$4\n"
    "move $4,$18\n"
    "jal func_80075610\n"
    "sb $0,176($16)\n"
    "j func_80073A2C\n"
    "nop\n"
    ".end func_80076BE0\n.set at\n.set reorder\n");
