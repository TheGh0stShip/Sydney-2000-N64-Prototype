/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800762D8\n.ent func_800762D8\n"
    "func_800762D8:\n"
    "jal func_800D29E0\n"
    "move $4,$16\n"
    "jal func_800AC334\n"
    "move $4,$16\n"
    "lui $16,0x1\n"
    "ori $16,$16,0x940\n"
    "addu $16,$18,$16\n"
    ".end func_800762D8\n.set at\n.set reorder\n");
