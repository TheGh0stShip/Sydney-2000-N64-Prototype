/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800AB640\n.ent func_800AB640\n"
    "func_800AB640:\n"
    "lw $3,12($4)\n"
    "lw $2,8($4)\n"
    "sltu $2,$2,$3\n"
    "bnez $2,L_800AB65C\n"
    "addiu $2,$3,-4\n"
    "jr $31\n"
    "move $2,$0\n"
    "L_800AB65C:\n"
    "sw $2,12($4)\n"
    "lw $2,-4($3)\n"
    "jr $31\n"
    "nop\n"
    ".end func_800AB640\n.set at\n.set reorder\n");
