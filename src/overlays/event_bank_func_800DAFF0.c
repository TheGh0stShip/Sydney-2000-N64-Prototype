/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800DAFF0\n.ent func_800DAFF0\n"
    "func_800DAFF0:\n"
    "addiu $29,$29,-40\n"
    "sw $18,32($29)\n"
    "move $18,$4\n"
    "lui $2,0x8010\n"
    "lw $4,-15760($2)\n"
    "sw $31,36($29)\n"
    "sw $17,28($29)\n"
    "sw $16,24($29)\n"
    ".end func_800DAFF0\n.set at\n.set reorder\n");
