/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80080AE0\n.ent func_80080AE0\n"
    "func_80080AE0:\n"
    "lui $2,0x8008\n"
    "lui $1,0x8007\n"
    "lwc1 $f2,5148($1)\n"
    "lui $3,0x8008\n"
    "swc1 $f2,4($22)\n"
    "add.s $f2,$f0,$f0\n"
    "swc1 $f0,-30792($2)\n"
    "addiu $2,$3,-30816\n"
    ".end func_80080AE0\n.set at\n.set reorder\n");
