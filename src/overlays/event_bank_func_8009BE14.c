/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8009BE14\n.ent func_8009BE14\n"
    "func_8009BE14:\n"
    "addiu $29,$29,-24\n"
    "sw $16,16($29)\n"
    "move $16,$4\n"
    "li $2,0x8000\n"
    "addu $2,$16,$2\n"
    ".end func_8009BE14\n.set at\n.set reorder\n");
