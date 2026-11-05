/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800ED894\n.ent func_800ED894\n"
    "func_800ED894:\n"
    "addiu $29,$29,-24\n"
    "sw $16,16($29)\n"
    "move $16,$4\n"
    "sw $31,20($29)\n"
    "jal func_800EA260\n"
    "addiu $4,$16,220\n"
    "jal func_800EA260\n"
    "addiu $4,$16,192\n"
    "jal func_800EA260\n"
    "addiu $4,$16,248\n"
    "lw $31,20($29)\n"
    "lw $16,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_800ED894\n.set at\n.set reorder\n");
