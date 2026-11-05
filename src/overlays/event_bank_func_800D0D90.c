/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800D0D90\n.ent func_800D0D90\n"
    "func_800D0D90:\n"
    "trunc.w.s $f6,$f0\n"
    "mfc1 $5,$f6\n"
    "j func_80071244\n"
    "nop\n"
    ".end func_800D0D90\n.set at\n.set reorder\n");
