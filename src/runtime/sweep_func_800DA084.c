/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800DA084\n.ent func_800DA084\n"
    "func_800DA084:\n"
    "lui $2,0x8010\n"
    "lw $2,-15760($2)\n"
    ".end func_800DA084\n.set at\n.set reorder\n");
