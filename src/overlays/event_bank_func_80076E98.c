/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076E98\n.ent func_80076E98\n"
    "func_80076E98:\n"
    "sw $19,44($29)\n"
    "sw $17,36($29)\n"
    "sw $16,32($29)\n"
    "lbu $3,1556($18)\n"
    "addiu $2,$3,-2\n"
    ".end func_80076E98\n.set at\n.set reorder\n");
