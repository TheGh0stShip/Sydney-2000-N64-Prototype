/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007BBB0\n.ent func_8007BBB0\n"
    "func_8007BBB0:\n"
    "li $5,26\n"
    "move $6,$0\n"
    "jal func_80077EEC\n"
    "move $7,$6\n"
    "lw $2,4($21)\n"
    "sw $2,16($19)\n"
    "lw $31,64($29)\n"
    "lw $21,60($29)\n"
    "lw $20,56($29)\n"
    "lw $19,52($29)\n"
    "lw $18,48($29)\n"
    "lw $17,44($29)\n"
    "lw $16,40($29)\n"
    ".end func_8007BBB0\n.set at\n.set reorder\n");
