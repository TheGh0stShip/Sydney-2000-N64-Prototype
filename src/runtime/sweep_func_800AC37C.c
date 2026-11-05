/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800AC37C\n.ent func_800AC37C\n"
    "func_800AC37C:\n"
    "lw $2,4($4)\n"
    "bnez $2,L_800AC39C\n"
    "li $2,1\n"
    "sw $5,4($4)\n"
    "lw $3,8($5)\n"
    "sw $3,12($4)\n"
    "jr $31\n"
    "sw $4,8($5)\n"
    "L_800AC39C:\n"
    "jr $31\n"
    "move $2,$0\n"
    ".end func_800AC37C\n.set at\n.set reorder\n");
