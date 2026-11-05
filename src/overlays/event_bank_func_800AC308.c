/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800AC308\n.ent func_800AC308\n"
    "func_800AC308:\n"
    ".word 0x14400012\n"
    "nop\n"
    "lw $2,8($17)\n"
    "lw $4,4($17)\n"
    "sw $2,12($17)\n"
    "lw $2,12($17)\n"
    "addiu $18,$18,-1\n"
    "sw $4,0($2)\n"
    "addiu $4,$4,528\n"
    "lw $2,12($17)\n"
    "lhu $3,18($17)\n"
    ".end func_800AC308\n.set at\n.set reorder\n");
