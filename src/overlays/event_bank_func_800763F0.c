/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800763F0\n.ent func_800763F0\n"
    "func_800763F0:\n"
    "jal func_800AC334\n"
    "move $4,$16\n"
    "jal func_8007E098\n"
    "move $4,$16\n"
    "lui $16,0x1\n"
    "ori $16,$16,0xb20\n"
    "lui $4,0x800f\n"
    ".end func_800763F0\n.set at\n.set reorder\n");
