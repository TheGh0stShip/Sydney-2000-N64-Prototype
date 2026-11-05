/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80072F18\n.ent func_80072F18\n"
    "func_80072F18:\n"
    "lw $5,0($2)\n"
    "j func_800734E0\n"
    "li $6,-1\n"
    ".end func_80072F18\n.set at\n.set reorder\n");
