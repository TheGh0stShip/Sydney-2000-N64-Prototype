/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076DF0\n.ent func_80076DF0\n"
    "func_80076DF0:\n"
    "li $19,1\n"
    "sb $19,427($16)\n"
    "sb $2,425($16)\n"
    "lw $2,732($17)\n"
    "move $6,$19\n"
    "sw $2,732($16)\n"
    "lbu $7,424($17)\n"
    "li $2,3\n"
    "sw $2,16($29)\n"
    ".end func_80076DF0\n.set at\n.set reorder\n");
