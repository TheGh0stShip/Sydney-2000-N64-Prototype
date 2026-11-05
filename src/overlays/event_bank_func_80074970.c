/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80074970\n.ent func_80074970\n"
    "func_80074970:\n"
    "lui $16,0x800f\n"
    "addiu $16,$16,6880\n"
    "move $4,$16\n"
    "li $5,220\n"
    "move $6,$0\n"
    ".end func_80074970\n.set at\n.set reorder\n");
