/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076B34\n.ent func_80076B34\n"
    "func_80076B34:\n"
    "addiu $29,$29,-40\n"
    "sw $18,32($29)\n"
    "move $18,$4\n"
    "lui $2,0x1\n"
    "sw $16,24($29)\n"
    "addu $16,$18,$2\n"
    "sw $31,36($29)\n"
    "sw $17,28($29)\n"
    "lw $2,3400($16)\n"
    ".end func_80076B34\n.set at\n.set reorder\n");
