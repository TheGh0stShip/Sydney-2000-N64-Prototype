/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800CA7C8\n.ent func_800CA7C8\n"
    "func_800CA7C8:\n"
    "lw $18,72($29)\n"
    "lw $17,68($29)\n"
    "lw $16,64($29)\n"
    "jr $31\n"
    "addiu $29,$29,96\n"
    ".end func_800CA7C8\n.set at\n.set reorder\n");
