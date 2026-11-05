/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800971EC\n.ent func_800971EC\n"
    "func_800971EC:\n"
    "lw $2,0($3)\n"
    "jr $2\n"
    "nop\n"
    ".end func_800971EC\n.set at\n.set reorder\n");
