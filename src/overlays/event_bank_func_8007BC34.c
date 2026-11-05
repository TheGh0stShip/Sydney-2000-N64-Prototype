/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007BC34\n.ent func_8007BC34\n"
    "func_8007BC34:\n"
    "li $2,2\n"
    "lbu $2,3224($18)\n"
    "lw $4,21356($19)\n"
    "sll $5,$2,0x2\n"
    "addu $5,$5,$2\n"
    "lw $2,3256($18)\n"
    "sllv $5,$5,$16\n"
    ".end func_8007BC34\n.set at\n.set reorder\n");
