/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80075050\n.ent func_80075050\n"
    "func_80075050:\n"
    "li $2,0xb400\n"
    "sw $2,1216($18)\n"
    "li $2,14\n"
    "jal func_80083298\n"
    "sw $2,1552($18)\n"
    "j func_80072550\n"
    "nop\n"
    ".end func_80075050\n.set at\n.set reorder\n");
