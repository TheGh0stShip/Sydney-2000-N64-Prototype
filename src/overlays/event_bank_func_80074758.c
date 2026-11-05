/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80074758\n.ent func_80074758\n"
    "func_80074758:\n"
    "sb $2,2840($4)\n"
    "andi $2,$2,0xff\n"
    ".word 0x14430123\n"
    "lui $2,0x800f\n"
    "sw $0,10024($2)\n"
    "li $2,-7680\n"
    ".end func_80074758\n.set at\n.set reorder\n");
