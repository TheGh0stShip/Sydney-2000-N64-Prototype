/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8009BF34\n.ent func_8009BF34\n"
    "func_8009BF34:\n"
    "mfc1 $5,$f0\n"
    "jal func_80074B14\n"
    "move $4,$16\n"
    "move $4,$16\n"
    "jal func_800762A8\n"
    "li $5,1\n"
    "lw $31,20($29)\n"
    "lw $16,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_8009BF34\n.set at\n.set reorder\n");
