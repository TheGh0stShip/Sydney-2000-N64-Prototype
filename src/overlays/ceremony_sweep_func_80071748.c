/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80071748\n.ent func_80071748\n"
    "func_80071748:\n"
    "li $6,4\n"
    "lw $31,172($29)\n"
    "lw $22,168($29)\n"
    "lw $21,164($29)\n"
    "lw $20,160($29)\n"
    "lw $19,156($29)\n"
    "lw $18,152($29)\n"
    "lw $17,148($29)\n"
    "lw $16,144($29)\n"
    "ldc1 $f20,176($29)\n"
    "jr $31\n"
    "addiu $29,$29,184\n"
    ".end func_80071748\n.set at\n.set reorder\n");
