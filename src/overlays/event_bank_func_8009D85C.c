/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8009D85C\n.ent func_8009D85C\n"
    "func_8009D85C:\n"
    "lw $2,24072($18)\n"
    "addiu $2,$2,-256\n"
    ".word 0x1C4001C9\n"
    "sw $2,24072($18)\n"
    "li $2,15360\n"
    "sw $2,24072($18)\n"
    "j func_80071B34\n"
    ".end func_8009D85C\n.set at\n.set reorder\n");
