/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8009F880\n.ent func_8009F880\n"
    "func_8009F880:\n"
    "addiu $29,$29,-24\n"
    "sw $16,16($29)\n"
    "sw $31,20($29)\n"
    "jal func_8001457C\n"
    "move $16,$4\n"
    "jal func_8001457C\n"
    "addiu $4,$16,476\n"
    "jal func_8001457C\n"
    "addiu $4,$16,700\n"
    "lw $31,20($29)\n"
    "lw $16,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_8009F880\n.set at\n.set reorder\n");
