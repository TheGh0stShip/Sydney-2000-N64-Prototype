/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800BB8C0\n.ent func_800BB8C0\n"
    "func_800BB8C0:\n"
    "lwc1 $f0,12($4)\n"
    "lwc1 $f4,8($4)\n"
    "sub.s $f0,$f0,$f4\n"
    "lui $1,0x8008\n"
    "lwc1 $f2,28448($1)\n"
    "mul.s $f0,$f0,$f2\n"
    "jr $31\n"
    "add.s $f0,$f0,$f4\n"
    ".end func_800BB8C0\n.set at\n.set reorder\n");
