/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800BB99C\n.ent func_800BB99C\n"
    "func_800BB99C:\n"
    "jal func_800BB8C0\n"
    "move $4,$16\n"
    "lwc1 $f2,17468($19)\n"
    "mul.s $f0,$f0,$f2\n"
    "lui $1,0x8007\n"
    "lwc1 $f2,2100($1)\n"
    "mul.s $f0,$f0,$f2\n"
    "lui $1,0x8007\n"
    "lwc1 $f4,2104($1)\n"
    ".end func_800BB99C\n.set at\n.set reorder\n");
