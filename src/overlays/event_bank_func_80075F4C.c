/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80075F4C\n.ent func_80075F4C\n"
    "func_80075F4C:\n"
    ".word 0x14400012\n"
    "nop\n"
    "lw $2,8($17)\n"
    "lw $4,4($17)\n"
    "sw $2,12($17)\n"
    "lw $2,12($17)\n"
    "addiu $18,$18,-1\n"
    "sw $4,0($2)\n"
    "addiu $4,$4,528\n"
    ".end func_80075F4C\n.set at\n.set reorder\n");
