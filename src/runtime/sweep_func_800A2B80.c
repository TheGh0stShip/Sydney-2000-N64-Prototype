/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800A2B80\n.ent func_800A2B80\n"
    "func_800A2B80:\n"
    "addiu $29,$29,-24\n"
    "sw $16,16($29)\n"
    "move $16,$4\n"
    "sw $31,20($29)\n"
    "jal func_800A0224\n"
    "addiu $4,$16,240\n"
    "jal func_800A27CC\n"
    "move $4,$16\n"
    "lw $31,20($29)\n"
    "lw $16,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_800A2B80\n.set at\n.set reorder\n");
