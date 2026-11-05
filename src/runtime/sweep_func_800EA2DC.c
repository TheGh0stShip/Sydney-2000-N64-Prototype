/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800EA2DC\n.ent func_800EA2DC\n"
    "func_800EA2DC:\n"
    "addiu $29,$29,-24\n"
    "sw $31,16($29)\n"
    "lw $3,0($5)\n"
    "li $2,5\n"
    "bne $3,$2,L_800EA2FC\n"
    "nop\n"
    "jal func_800E9D10\n"
    "nop\n"
    "L_800EA2FC:\n"
    "lw $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_800EA2DC\n.set at\n.set reorder\n");
