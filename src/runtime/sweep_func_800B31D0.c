/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800B31D0\n.ent func_800B31D0\n"
    "func_800B31D0:\n"
    "lui $2,0x800f\n"
    "jr $31\n"
    "sw $0,9924($2)\n"
    ".end func_800B31D0\n.set at\n.set reorder\n");
