/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80080AD0\n.ent func_80080AD0\n"
    "func_80080AD0:\n"
    "lwc1 $f6,5144($1)\n"
    "li $20,1\n"
    "swc1 $f10,-30804($30)\n"
    "mul.s $f10,$f0,$f6\n"
    ".end func_80080AD0\n.set at\n.set reorder\n");
