/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8008D054\n.ent func_8008D054\n"
    "func_8008D054:\n"
    "lui $2,0x800f\n"
    "lw $2,10096($2)\n"
    ".end func_8008D054\n.set at\n.set reorder\n");
