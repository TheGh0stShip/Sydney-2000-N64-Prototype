/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800CCAE0\n.ent func_800CCAE0\n"
    "func_800CCAE0:\n"
    "lwc1 $f2,2352($1)\n"
    "c.le.s $f2,$f0\n"
    "nop\n"
    "bc1tl L_800CCB04\n"
    "sub.s $f0,$f0,$f2\n"
    "trunc.w.s $f6,$f0\n"
    "mfc1 $3,$f6\n"
    "j func_80071BF8\n"
    "move $4,$19\n"
    "L_800CCB04:\n"
    "lui $2,0x8000\n"
    "trunc.w.s $f6,$f0\n"
    ".end func_800CCAE0\n.set at\n.set reorder\n");
