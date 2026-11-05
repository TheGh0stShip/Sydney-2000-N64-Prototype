/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800AD7D0\n.ent func_800AD7D0\n"
    "func_800AD7D0:\n"
    "addu $4,$17,$4\n"
    "lui $4,0x800f\n"
    "addiu $4,$4,10072\n"
    "jal func_800AA658\n"
    "addiu $5,$18,11704\n"
    "lw $31,36($29)\n"
    "lw $18,32($29)\n"
    "lw $17,28($29)\n"
    "lw $16,24($29)\n"
    "jr $31\n"
    "addiu $29,$29,40\n"
    ".end func_800AD7D0\n.set at\n.set reorder\n");
