/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007AE34\n.ent func_8007AE34\n"
    "func_8007AE34:\n"
    "lui $2,0x800f\n"
    "sw $0,2580($3)\n"
    "lw $5,10052($2)\n"
    "move $7,$19\n"
    ".end func_8007AE34\n.set at\n.set reorder\n");
