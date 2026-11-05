/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800BAC24\n.ent func_800BAC24\n"
    "func_800BAC24:\n"
    "lui $4,0x800f\n"
    "lw $2,10816($4)\n"
    ".end func_800BAC24\n.set at\n.set reorder\n");
