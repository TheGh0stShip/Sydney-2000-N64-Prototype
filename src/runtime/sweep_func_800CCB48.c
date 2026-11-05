/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800CCB48\n.ent func_800CCB48\n"
    "func_800CCB48:\n"
    "addiu $29,$29,-24\n"
    "sw $31,16($29)\n"
    "lw $3,0($5)\n"
    "li $2,5\n"
    "bne $3,$2,L_800CCB68\n"
    "nop\n"
    "jal func_800CC7EC\n"
    "nop\n"
    "L_800CCB68:\n"
    "lw $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_800CCB48\n.set at\n.set reorder\n");
