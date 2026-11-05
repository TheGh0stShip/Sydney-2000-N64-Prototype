/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007B7F0\n.ent func_8007B7F0\n"
    "func_8007B7F0:\n"
    "lw $2,21356($19)\n"
    "lui $1,0x8007\n"
    "lwc1 $f0,4412($1)\n"
    "swc1 $f0,88($2)\n"
    ".end func_8007B7F0\n.set at\n.set reorder\n");
