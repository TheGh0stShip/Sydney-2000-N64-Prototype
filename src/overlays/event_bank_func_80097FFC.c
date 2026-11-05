/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80097FFC\n.ent func_80097FFC\n"
    "func_80097FFC:\n"
    "addiu $29,$29,-40\n"
    "sw $19,28($29)\n"
    "move $19,$4\n"
    "li $2,0x8000\n"
    "addu $3,$19,$2\n"
    ".end func_80097FFC\n.set at\n.set reorder\n");
