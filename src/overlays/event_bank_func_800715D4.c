/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800715D4\n.ent func_800715D4\n"
    "func_800715D4:\n"
    "jal func_800AD434\n"
    "swc1 $f20,0($2)\n"
    "addiu $4,$21,4464\n"
    "lui $1,0x8007\n"
    "lwc1 $f0,3168($1)\n"
    "mtc1 $20,$f2\n"
    "cvt.s.w $f2,$f2\n"
    "mul.s $f2,$f2,$f0\n"
    ".end func_800715D4\n.set at\n.set reorder\n");
