/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800EA494\n.ent func_800EA494\n"
    "func_800EA494:\n"
    "lw $2,188($4)\n"
    "sw $2,12($5)\n"
    "lw $2,184($4)\n"
    "sw $5,188($4)\n"
    "addiu $2,$2,1\n"
    "jr $31\n"
    "sw $2,184($4)\n"
    ".end func_800EA494\n.set at\n.set reorder\n");
