/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80083520\n.ent func_80083520\n"
    "func_80083520:\n"
    "lbu $3,1557($19)\n"
    "sltiu $2,$3,6\n"
    ".word 0x10400045\n"
    "lui $2,0x8007\n"
    "addiu $2,$2,4232\n"
    "sll $3,$3,0x2\n"
    "addu $3,$3,$2\n"
    "lw $2,0($3)\n"
    "jr $2\n"
    "nop\n"
    ".end func_80083520\n.set at\n.set reorder\n");
