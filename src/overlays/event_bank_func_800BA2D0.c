/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800BA2D0\n.ent func_800BA2D0\n"
    "func_800BA2D0:\n"
    "lwc1 $f2,4($5)\n"
    "add.s $f0,$f0,$f2\n"
    "swc1 $f0,4($2)\n"
    "lwc1 $f0,8($2)\n"
    "lwc1 $f2,8($5)\n"
    "j func_80072130\n"
    "add.s $f0,$f0,$f2\n"
    ".end func_800BA2D0\n.set at\n.set reorder\n");
