/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80078F18\n.ent func_80078F18\n"
    "func_80078F18:\n"
    "lwc1 $f2,3384($1)\n"
    "sub.s $f2,$f2,$f4\n"
    "lui $1,0x8007\n"
    "lwc1 $f0,3388($1)\n"
    "mul.s $f2,$f2,$f0\n"
    "swc1 $f4,2($16)\n"
    "trunc.w.s $f8,$f2\n"
    "mfc1 $2,$f8\n"
    "sh $2,0($16)\n"
    "addiu $16,$16,12\n"
    "addiu $17,$17,12\n"
    "j func_80075A8C\n"
    "addiu $18,$18,1\n"
    ".end func_80078F18\n.set at\n.set reorder\n");
