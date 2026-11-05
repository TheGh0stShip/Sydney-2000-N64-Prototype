/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076AF8\n.ent func_80076AF8\n"
    "func_80076AF8:\n"
    "li $6,1\n"
    "move $7,$18\n"
    "jal func_800BBD78\n"
    "sw $17,16($29)\n"
    "lw $31,56($29)\n"
    "lw $23,52($29)\n"
    "lw $22,48($29)\n"
    ".end func_80076AF8\n.set at\n.set reorder\n");
