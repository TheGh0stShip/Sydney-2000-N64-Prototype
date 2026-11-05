/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800B7048\n.ent func_800B7048\n"
    "func_800B7048:\n"
    "lui $2,0x8010\n"
    "lw $3,-15760($2)\n"
    "lbu $2,3410($3)\n"
    "jr $31\n"
    "sb $2,3413($3)\n"
    ".end func_800B7048\n.set at\n.set reorder\n");
