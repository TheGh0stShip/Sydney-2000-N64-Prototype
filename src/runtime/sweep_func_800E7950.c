/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800E7950\n.ent func_800E7950\n"
    "func_800E7950:\n"
    "lui $2,0x800f\n"
    "lw $2,10096($2)\n"
    ".end func_800E7950\n.set at\n.set reorder\n");
