/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800B6240\n.ent func_800B6240\n"
    "func_800B6240:\n"
    "addiu $29,$29,-24\n"
    "sw $31,16($29)\n"
    "lbu $2,23423($4)\n"
    "addiu $2,$2,-3\n"
    "sltiu $2,$2,2\n"
    "bnez $2,L_800B6268\n"
    "nop\n"
    "lui $4,0x800f\n"
    "jal func_800C0110\n"
    "addiu $4,$4,15296\n"
    "L_800B6268:\n"
    "lw $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_800B6240\n.set at\n.set reorder\n");
