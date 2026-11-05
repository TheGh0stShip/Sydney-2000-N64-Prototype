/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80075510\n.ent func_80075510\n"
    "func_80075510:\n"
    "jal func_8009AC98\n"
    "li $7,4\n"
    "lui $2,0x1\n"
    "ori $2,$2,0xc200\n"
    "move $4,$18\n"
    "sw $2,1216($4)\n"
    "li $2,27\n"
    "jal func_80074690\n"
    "sw $2,1552($4)\n"
    "j func_80072550\n"
    "nop\n"
    ".end func_80075510\n.set at\n.set reorder\n");
