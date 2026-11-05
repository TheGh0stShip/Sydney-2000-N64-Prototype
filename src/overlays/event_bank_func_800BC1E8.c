/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800BC1E8\n.ent func_800BC1E8\n"
    "func_800BC1E8:\n"
    "addiu $6,$29,56\n"
    "jal func_800B9964\n"
    "addiu $7,$29,40\n"
    "lwc1 $f0,4644($19)\n"
    "neg.s $f0,$f0\n"
    "mfc1 $5,$f0\n"
    "jal func_800721A0\n"
    "move $4,$19\n"
    "move $4,$16\n"
    "jal func_800AD9E8\n"
    "sw $0,4644($19)\n"
    "j func_80071928\n"
    "nop\n"
    ".end func_800BC1E8\n.set at\n.set reorder\n");
