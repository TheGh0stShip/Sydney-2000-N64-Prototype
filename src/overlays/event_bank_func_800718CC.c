/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800718CC\n.ent func_800718CC\n"
    "func_800718CC:\n"
    "lw $2,196($21)\n"
    ".word 0x10400005\n"
    "nop\n"
    "lui $1,0x8007\n"
    "lwc1 $f0,3180($1)\n"
    ".end func_800718CC\n.set at\n.set reorder\n");
