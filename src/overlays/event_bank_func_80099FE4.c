/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80099FE4\n.ent func_80099FE4\n"
    "func_80099FE4:\n"
    "move $4,$18\n"
    "lw $31,72($29)\n"
    "lw $21,68($29)\n"
    "lw $20,64($29)\n"
    "lw $19,60($29)\n"
    "lw $18,56($29)\n"
    "lw $17,52($29)\n"
    "lw $16,48($29)\n"
    "jr $31\n"
    "addiu $29,$29,80\n"
    ".end func_80099FE4\n.set at\n.set reorder\n");
