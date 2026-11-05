/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8009BE28\n.ent func_8009BE28\n"
    "func_8009BE28:\n"
    "li $3,1\n"
    "addiu $4,$16,14548\n"
    "sw $31,20($29)\n"
    "jal func_800CEE04\n"
    "sw $3,124($2)\n"
    "jal func_80097504\n"
    "addiu $4,$16,15860\n"
    "lw $31,20($29)\n"
    "lw $16,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_8009BE28\n.set at\n.set reorder\n");
