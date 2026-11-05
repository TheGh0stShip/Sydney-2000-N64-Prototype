/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007D6BC\n.ent func_8007D6BC\n"
    "func_8007D6BC:\n"
    "li $2,0x8000\n"
    "addu $18,$20,$2\n"
    "lbu $2,3229($18)\n"
    "li $19,2\n"
    ".word 0x54530006\n"
    "lui $17,0x8008\n"
    "jal func_800CCB0C\n"
    ".end func_8007D6BC\n.set at\n.set reorder\n");
