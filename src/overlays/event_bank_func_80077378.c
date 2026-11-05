/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80077378\n.ent func_80077378\n"
    "func_80077378:\n"
    "lw $20,56($29)\n"
    "lw $19,52($29)\n"
    "lw $18,48($29)\n"
    "lw $17,44($29)\n"
    "lw $16,40($29)\n"
    "jr $31\n"
    "addiu $29,$29,72\n"
    ".end func_80077378\n.set at\n.set reorder\n");
