/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076A04\n.ent func_80076A04\n"
    "func_80076A04:\n"
    "sw $2,72($3)\n"
    "li $11,3\n"
    "andi $17,$19,0xff\n"
    ".end func_80076A04\n.set at\n.set reorder\n");
