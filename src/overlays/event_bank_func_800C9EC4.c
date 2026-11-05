/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800C9EC4\n.ent func_800C9EC4\n"
    "func_800C9EC4:\n"
    "addiu $29,$29,-96\n"
    "sw $18,72($29)\n"
    "move $18,$4\n"
    "sw $21,84($29)\n"
    "move $21,$5\n"
    "sw $16,64($29)\n"
    "addiu $16,$18,17136\n"
    "sw $31,88($29)\n"
    "sw $20,80($29)\n"
    "sw $19,76($29)\n"
    ".word 0x12A00232\n"
    "sw $17,68($29)\n"
    "lw $3,18228($18)\n"
    ".end func_800C9EC4\n.set at\n.set reorder\n");
