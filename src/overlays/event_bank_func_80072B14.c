/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80072B14\n.ent func_80072B14\n"
    "func_80072B14:\n"
    "move $4,$22\n"
    "lui $8,0x8007\n"
    "mfc1 $7,$f20\n"
    ".end func_80072B14\n.set at\n.set reorder\n");
