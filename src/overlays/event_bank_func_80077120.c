/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80077120\n.ent func_80077120\n"
    "func_80077120:\n"
    "sll $16,$16,0x3\n"
    "addu $16,$16,$2\n"
    "sll $16,$16,0x4\n"
    "addu $2,$16,$18\n"
    "addiu $17,$18,3660\n"
    "move $4,$17\n"
    "lw $6,24($29)\n"
    "lbu $5,28564($2)\n"
    "jal func_8009D360\n"
    "negu $6,$6\n"
    "jal func_8009D854\n"
    ".end func_80077120\n.set at\n.set reorder\n");
