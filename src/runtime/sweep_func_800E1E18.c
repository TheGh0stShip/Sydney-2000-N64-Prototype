/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800E1E18\n.ent func_800E1E18\n"
    "func_800E1E18:\n"
    "lui $2,0x8010\n"
    "lw $4,-15760($2)\n"
    "lhu $2,2538($4)\n"
    ".end func_800E1E18\n.set at\n.set reorder\n");
