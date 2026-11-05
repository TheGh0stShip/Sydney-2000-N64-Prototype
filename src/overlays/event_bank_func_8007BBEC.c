/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007BBEC\n.ent func_8007BBEC\n"
    "func_8007BBEC:\n"
    "addiu $29,$29,-48\n"
    "sw $19,36($29)\n"
    "move $19,$4\n"
    "li $2,0x8000\n"
    "sw $18,32($29)\n"
    ".end func_8007BBEC\n.set at\n.set reorder\n");
