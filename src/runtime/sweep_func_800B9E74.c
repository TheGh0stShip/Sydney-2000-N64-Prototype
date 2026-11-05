/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800B9E74\n.ent func_800B9E74\n"
    "func_800B9E74:\n"
    "lw $2,324($4)\n"
    "lui $3,0x8000\n"
    "and $2,$2,$3\n"
    "or $2,$2,$5\n"
    "sw $2,324($4)\n"
    "jr $31\n"
    "move $2,$0\n"
    ".end func_800B9E74\n.set at\n.set reorder\n");
