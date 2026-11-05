/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007B7D4\n.ent func_8007B7D4\n"
    "func_8007B7D4:\n"
    "beqz $4,L_8007B7F0\n"
    "nop\n"
    "lw $2,21356($19)\n"
    "lui $1,0x8007\n"
    "lwc1 $f0,4408($1)\n"
    "j func_80072570\n"
    "swc1 $f0,88($2)\n"
    "L_8007B7F0:\n"
    ".end func_8007B7D4\n.set at\n.set reorder\n");
