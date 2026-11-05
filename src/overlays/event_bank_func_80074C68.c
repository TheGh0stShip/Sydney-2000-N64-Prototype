/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80074C68\n.ent func_80074C68\n"
    "func_80074C68:\n"
    "sw $2,10112($3)\n"
    "li $2,0x8000\n"
    "addu $2,$18,$2\n"
    "li $3,15\n"
    "jal func_80072EE4\n"
    "sw $3,22864($2)\n"
    "lw $3,1552($18)\n"
    ".end func_80074C68\n.set at\n.set reorder\n");
