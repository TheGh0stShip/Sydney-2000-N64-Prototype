/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800771D4\n.ent func_800771D4\n"
    "func_800771D4:\n"
    "lui $2,0x1\n"
    "lw $5,-15760($4)\n"
    "addu $2,$21,$2\n"
    "sw $31,64($29)\n"
    "sw $20,56($29)\n"
    "sw $19,52($29)\n"
    "sw $18,48($29)\n"
    "sw $17,44($29)\n"
    "sw $16,40($29)\n"
    ".end func_800771D4\n.set at\n.set reorder\n");
