/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800DC9D4\n.ent func_800DC9D4\n"
    "func_800DC9D4:\n"
    "lui $2,0x800f\n"
    "lw $2,25572($2)\n"
    ".end func_800DC9D4\n.set at\n.set reorder\n");
