/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800767D4\n.ent func_800767D4\n"
    "func_800767D4:\n"
    "lw $31,48($29)\n"
    "lw $21,44($29)\n"
    "lw $20,40($29)\n"
    "lw $19,36($29)\n"
    "lw $18,32($29)\n"
    "lw $17,28($29)\n"
    "lw $16,24($29)\n"
    "jr $31\n"
    "addiu $29,$29,56\n"
    ".end func_800767D4\n.set at\n.set reorder\n");
