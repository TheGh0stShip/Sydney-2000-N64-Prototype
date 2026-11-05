/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80071E44\n.ent func_80071E44\n"
    "func_80071E44:\n"
    "lb $7,76($2)\n"
    "jal func_800BC1E8\n"
    "move $6,$5\n"
    "move $4,$16\n"
    "lw $2,-15760($17)\n"
    ".end func_80071E44\n.set at\n.set reorder\n");
