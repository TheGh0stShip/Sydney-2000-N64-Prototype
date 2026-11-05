/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80071D14\n.ent func_80071D14\n"
    "func_80071D14:\n"
    "sw $2,232($21)\n"
    "sw $2,236($21)\n"
    "lw $2,228($21)\n"
    "lw $3,232($21)\n"
    "lw $4,236($21)\n"
    ".end func_80071D14\n.set at\n.set reorder\n");
