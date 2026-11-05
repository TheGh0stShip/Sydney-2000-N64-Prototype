/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800CC448\n.ent func_800CC448\n"
    "func_800CC448:\n"
    "sll $5,$5,0x10\n"
    "sra $5,$5,0x10\n"
    "mtc1 $5,$f0\n"
    "cvt.s.w $f0,$f0\n"
    "addiu $4,$4,96\n"
    "sll $6,$6,0x10\n"
    "sra $6,$6,0x10\n"
    "swc1 $f0,64($4)\n"
    "mtc1 $6,$f0\n"
    "cvt.s.w $f0,$f0\n"
    "swc1 $f0,68($4)\n"
    "jr $31\n"
    "sw $0,72($4)\n"
    ".end func_800CC448\n.set at\n.set reorder\n");
