/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076DA4\n.ent func_80076DA4\n"
    "func_80076DA4:\n"
    "addiu $29,$29,-48\n"
    "sw $18,32($29)\n"
    "move $18,$4\n"
    "sw $16,24($29)\n"
    "addiu $16,$18,28608\n"
    "move $4,$16\n"
    "move $5,$18\n"
    "li $2,4\n"
    "sw $31,40($29)\n"
    ".end func_80076DA4\n.set at\n.set reorder\n");
