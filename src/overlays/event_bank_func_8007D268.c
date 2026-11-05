/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007D268\n.ent func_8007D268\n"
    "func_8007D268:\n"
    "addiu $5,$20,592\n"
    "lui $1,0x8007\n"
    "lwc1 $f0,4828($1)\n"
    ".end func_8007D268\n.set at\n.set reorder\n");
