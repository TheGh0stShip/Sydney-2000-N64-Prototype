/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076910\n.ent func_80076910\n"
    "func_80076910:\n"
    "addiu $29,$29,-64\n"
    "sw $18,32($29)\n"
    "move $18,$4\n"
    "sw $19,36($29)\n"
    ".end func_80076910\n.set at\n.set reorder\n");
