/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800720A8\n.ent func_800720A8\n"
    "func_800720A8:\n"
    "lui $4,0x800f\n"
    "jal func_800A32CC\n"
    "addiu $4,$4,6880\n"
    "jal func_800AC334\n"
    "move $4,$16\n"
    "jal func_800C0168\n"
    "move $4,$16\n"
    "lui $4,0x800f\n"
    ".end func_800720A8\n.set at\n.set reorder\n");
