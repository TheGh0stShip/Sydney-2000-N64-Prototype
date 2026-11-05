/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076B94\n.ent func_80076B94\n"
    "func_80076B94:\n"
    "li $2,2\n"
    ".word 0x1462000E\n"
    "li $2,5\n"
    "lui $4,0x800f\n"
    "addiu $4,$4,15296\n"
    "lui $2,0x800f\n"
    "sw $0,10024($2)\n"
    "li $2,-7680\n"
    ".end func_80076B94\n.set at\n.set reorder\n");
