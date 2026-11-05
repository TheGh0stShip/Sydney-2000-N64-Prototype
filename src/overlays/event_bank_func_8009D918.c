/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8009D918\n.ent func_8009D918\n"
    "func_8009D918:\n"
    "li $2,7680\n"
    "sw $2,24072($18)\n"
    "li $2,13\n"
    "j func_800721CC\n"
    "sb $2,24039($18)\n"
    ".end func_8009D918\n.set at\n.set reorder\n");
