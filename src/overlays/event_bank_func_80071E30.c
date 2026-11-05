/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80071E30\n.ent func_80071E30\n"
    "func_80071E30:\n"
    "jal func_800BC274\n"
    "lui $17,0x8010\n"
    "move $4,$16\n"
    ".end func_80071E30\n.set at\n.set reorder\n");
