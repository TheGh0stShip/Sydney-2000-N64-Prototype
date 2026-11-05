/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800DB0CC\n.ent func_800DB0CC\n"
    "func_800DB0CC:\n"
    "lhu $2,0($4)\n"
    "beqz $2,L_800DB0E8\n"
    "move $3,$0\n"
    "L_800DB0D8:\n"
    "addiu $4,$4,2\n"
    "lhu $2,0($4)\n"
    "bnez $2,L_800DB0D8\n"
    "addiu $3,$3,1\n"
    "L_800DB0E8:\n"
    "andi $2,$3,0xffff\n"
    "jr $31\n"
    "addiu $2,$2,1\n"
    ".end func_800DB0CC\n.set at\n.set reorder\n");
