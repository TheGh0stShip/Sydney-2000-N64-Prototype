/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800A3298\n.ent func_800A3298\n"
    "func_800A3298:\n"
    "addiu $29,$29,-32\n"
    "sw $16,16($29)\n"
    "move $16,$4\n"
    "sw $17,20($29)\n"
    "sw $31,24($29)\n"
    "jal func_800A3240\n"
    "move $17,$5\n"
    "sw $17,84($16)\n"
    "lw $31,24($29)\n"
    "lw $17,20($29)\n"
    "lw $16,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,32\n"
    ".end func_800A3298\n.set at\n.set reorder\n");
