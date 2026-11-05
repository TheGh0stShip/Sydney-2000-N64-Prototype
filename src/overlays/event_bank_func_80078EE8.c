/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80078EE8\n.ent func_80078EE8\n"
    "func_80078EE8:\n"
    "mul.s $f4,$f4,$f0\n"
    "lui $1,0x8007\n"
    "lwc1 $f2,3372($1)\n"
    "mul.s $f2,$f6,$f2\n"
    "lui $1,0x8007\n"
    "lwc1 $f0,3376($1)\n"
    "mul.s $f4,$f4,$f0\n"
    "lui $1,0x8007\n"
    "lwc1 $f0,3380($1)\n"
    "add.s $f4,$f4,$f0\n"
    "add.s $f4,$f4,$f2\n"
    "lui $1,0x8007\n"
    ".end func_80078EE8\n.set at\n.set reorder\n");
