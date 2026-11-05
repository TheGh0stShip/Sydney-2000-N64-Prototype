/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800BFFAC\n.ent func_800BFFAC\n"
    "func_800BFFAC:\n"
    "addiu $29,$29,-24\n"
    "lui $4,0x800f\n"
    "addiu $4,$4,15296\n"
    "lui $2,0x8009\n"
    "addiu $2,$2,-32240\n"
    "li $5,2\n"
    "sw $31,16($29)\n"
    "jal func_800AC3A4\n"
    "sw $2,180($4)\n"
    "lw $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_800BFFAC\n.set at\n.set reorder\n");
