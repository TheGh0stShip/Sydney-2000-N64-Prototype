/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800754C8\n.ent func_800754C8\n"
    "func_800754C8:\n"
    "jal func_8008382C\n"
    "nop\n"
    "lbu $3,1556($18)\n"
    "sltiu $2,$3,6\n"
    ".word 0x104000F5\n"
    "lui $2,0x8007\n"
    "addiu $2,$2,2840\n"
    "sll $3,$3,0x2\n"
    "addu $3,$3,$2\n"
    "lw $2,0($3)\n"
    "jr $2\n"
    "nop\n"
    ".end func_800754C8\n.set at\n.set reorder\n");
