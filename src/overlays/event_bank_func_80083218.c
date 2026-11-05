/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80083218\n.ent func_80083218\n"
    "func_80083218:\n"
    "lwc1 $f4,4188($1)\n"
    "lwc1 $f0,3344($2)\n"
    "cvt.s.w $f0,$f0\n"
    "j func_80071E80\n"
    "div.s $f0,$f0,$f2\n"
    ".end func_80083218\n.set at\n.set reorder\n");
