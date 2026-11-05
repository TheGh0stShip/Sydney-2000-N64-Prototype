/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800BC060\n.ent func_800BC060\n"
    "func_800BC060:\n"
    "lbu $2,1($4)\n"
    "beqz $2,L_800BC074\n"
    "nop\n"
    "lbu $2,0($4)\n"
    "andi $2,$2,0xf\n"
    "L_800BC074:\n"
    "jr $31\n"
    "nop\n"
    ".end func_800BC060\n.set at\n.set reorder\n");
