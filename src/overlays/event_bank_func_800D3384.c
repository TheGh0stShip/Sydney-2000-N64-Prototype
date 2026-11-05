/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800D3384\n.ent func_800D3384\n"
    "func_800D3384:\n"
    "addiu $29,$29,-40\n"
    "sw $18,24($29)\n"
    "move $18,$4\n"
    "sw $19,28($29)\n"
    "move $19,$5\n"
    "lui $2,0x8007\n"
    "addiu $2,$2,2328\n"
    ".end func_800D3384\n.set at\n.set reorder\n");
