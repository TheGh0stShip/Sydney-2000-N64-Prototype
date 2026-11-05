/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800D58E0\n.ent func_800D58E0\n"
    "func_800D58E0:\n"
    "lui $2,0x800f\n"
    "lw $2,25584($2)\n"
    ".end func_800D58E0\n.set at\n.set reorder\n");
