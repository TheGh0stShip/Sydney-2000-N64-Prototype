/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8009FD40\n.ent func_8009FD40\n"
    "func_8009FD40:\n"
    "slti $2,$3,7681\n"
    "bnez $2,L_8009FD50\n"
    "li $17,240\n"
    "li $17,238\n"
    "L_8009FD50:\n"
    "j func_800740E0\n"
    "sw $21,24128($18)\n"
    ".end func_8009FD40\n.set at\n.set reorder\n");
