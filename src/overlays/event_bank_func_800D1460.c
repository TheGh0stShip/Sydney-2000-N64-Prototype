/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800D1460\n.ent func_800D1460\n"
    "func_800D1460:\n"
    "lui $1,0x8007\n"
    "lwc1 $f2,2200($1)\n"
    "c.le.s $f2,$f0\n"
    "nop\n"
    ".word 0x45000013\n"
    "nop\n"
    "j func_80071960\n"
    "sub.s $f0,$f0,$f2\n"
    ".end func_800D1460\n.set at\n.set reorder\n");
