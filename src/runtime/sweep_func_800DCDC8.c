/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800DCDC8\n.ent func_800DCDC8\n"
    "func_800DCDC8:\n"
    "lw $2,444($4)\n"
    "bnez $2,L_800DCDDC\n"
    "nop\n"
    "jr $31\n"
    "move $2,$0\n"
    "L_800DCDDC:\n"
    "lhu $2,14($2)\n"
    "jr $31\n"
    "nop\n"
    ".end func_800DCDC8\n.set at\n.set reorder\n");
