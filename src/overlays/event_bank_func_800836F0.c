/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800836F0\n.ent func_800836F0\n"
    "func_800836F0:\n"
    "lui $2,0x8010\n"
    "lw $2,-15760($2)\n"
    "lw $3,2560($2)\n"
    "li $2,6\n"
    ".end func_800836F0\n.set at\n.set reorder\n");
