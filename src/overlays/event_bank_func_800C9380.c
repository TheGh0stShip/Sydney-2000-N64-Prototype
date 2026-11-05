/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800C9380\n.ent func_800C9380\n"
    "func_800C9380:\n"
    "addiu $29,$29,-136\n"
    "sw $22,72($29)\n"
    "move $22,$4\n"
    "sw $21,68($29)\n"
    "move $21,$0\n"
    "sw $17,52($29)\n"
    ".end func_800C9380\n.set at\n.set reorder\n");
