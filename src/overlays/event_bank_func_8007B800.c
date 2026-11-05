/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007B800\n.ent func_8007B800\n"
    "func_8007B800:\n"
    "lui $2,0x8010\n"
    "lw $2,-15760($2)\n"
    "lw $2,2560($2)\n"
    ".end func_8007B800\n.set at\n.set reorder\n");
