/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800DA720\n.ent func_800DA720\n"
    "func_800DA720:\n"
    "lui $4,0x8010\n"
    "lw $3,-15760($4)\n"
    ".end func_800DA720\n.set at\n.set reorder\n");
