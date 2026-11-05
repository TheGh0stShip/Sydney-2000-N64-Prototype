/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80083298\n.ent func_80083298\n"
    "func_80083298:\n"
    "li $3,1\n"
    "sb $3,185($2)\n"
    "sb $3,184($2)\n"
    "sb $0,186($2)\n"
    "sb $0,187($2)\n"
    "lui $2,0x800f\n"
    "lw $3,5104($2)\n"
    "li $2,9\n"
    ".end func_80083298\n.set at\n.set reorder\n");
