/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80080AA0\n.ent func_80080AA0\n"
    "func_80080AA0:\n"
    "addiu $7,$7,5108\n"
    "mtc1 $0,$f4\n"
    "li $19,36\n"
    "mul.s $f12,$f0,$f4\n"
    "lui $2,0x8008\n"
    "move $30,$2\n"
    "lui $1,0x8007\n"
    "lwc1 $f8,5140($1)\n"
    "addiu $2,$30,-30804\n"
    "mul.s $f14,$f0,$f8\n"
    "move $22,$2\n"
    "lui $1,0x8007\n"
    ".end func_80080AA0\n.set at\n.set reorder\n");
