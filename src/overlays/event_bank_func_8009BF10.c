/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8009BF10\n.ent func_8009BF10\n"
    "func_8009BF10:\n"
    "addiu $29,$29,-24\n"
    "sw $16,16($29)\n"
    "move $16,$4\n"
    "sw $31,20($29)\n"
    "jal func_80074664\n"
    "li $5,1\n"
    "lw $4,12136($16)\n"
    "jal func_8007AF50\n"
    "nop\n"
    ".end func_8009BF10\n.set at\n.set reorder\n");
