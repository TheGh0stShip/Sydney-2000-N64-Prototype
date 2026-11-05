/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80080F10\n.ent func_80080F10\n"
    "func_80080F10:\n"
    "swc1 $f0,0($2)\n"
    "lui $16,0x8008\n"
    "addiu $16,$16,-30708\n"
    "lui $1,0x8007\n"
    "lwc1 $f20,5332($1)\n"
    ".end func_80080F10\n.set at\n.set reorder\n");
