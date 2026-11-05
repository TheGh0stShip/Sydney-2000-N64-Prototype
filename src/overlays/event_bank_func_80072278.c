/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80072278\n.ent func_80072278\n"
    "func_80072278:\n"
    "lui $4,0x800f\n"
    "addiu $4,$4,10072\n"
    "jal func_800AA658\n"
    "addiu $5,$19,192\n"
    "lw $4,196($19)\n"
    ".word 0x10800014\n"
    "nop\n"
    "jal func_8007E394\n"
    "nop\n"
    ".end func_80072278\n.set at\n.set reorder\n");
