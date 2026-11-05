/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076804\n.ent func_80076804\n"
    "func_80076804:\n"
    "lui $4,0x800f\n"
    "addiu $4,$4,10968\n"
    "lui $2,0x800f\n"
    "sw $0,10020($2)\n"
    ".end func_80076804\n.set at\n.set reorder\n");
