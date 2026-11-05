/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800B9AD0\n.ent func_800B9AD0\n"
    "func_800B9AD0:\n"
    "add.s $f0,$f0,$f2\n"
    "lui $1,0x8007\n"
    "lwc1 $f4,3932($1)\n"
    "swc1 $f0,18764($18)\n"
    "lwc1 $f0,40($2)\n"
    "mul.s $f0,$f0,$f4\n"
    "lui $1,0x8007\n"
    "lwc1 $f2,3936($1)\n"
    "mul.s $f0,$f0,$f2\n"
    "add.s $f0,$f0,$f4\n"
    "jal func_800177AC\n"
    "swc1 $f0,18760($18)\n"
    "j func_80071B78\n"
    "nop\n"
    ".end func_800B9AD0\n.set at\n.set reorder\n");
