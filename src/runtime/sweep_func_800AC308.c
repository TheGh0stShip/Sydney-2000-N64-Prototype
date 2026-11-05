/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800AC308\n.ent func_800AC308\n"
    "func_800AC308:\n"
    "lw $3,8($4)\n"
    "sw $0,8($4)\n"
    "L_800AC310:\n"
    "beqz $3,L_800AC32C\n"
    "nop\n"
    "lw $2,12($3)\n"
    "sw $0,4($3)\n"
    "sw $0,12($3)\n"
    "j L_800AC310\n"
    "move $3,$2\n"
    "L_800AC32C:\n"
    "jr $31\n"
    "nop\n"
    ".end func_800AC308\n.set at\n.set reorder\n");
