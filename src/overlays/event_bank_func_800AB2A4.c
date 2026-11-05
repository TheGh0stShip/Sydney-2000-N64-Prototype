/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800AB2A4\n.ent func_800AB2A4\n"
    "func_800AB2A4:\n"
    "addiu $2,$2,-256\n"
    ".word 0x1C4001F9\n"
    "sw $2,300($3)\n"
    "lbu $3,286($3)\n"
    "sltiu $2,$3,6\n"
    ".word 0x104001F5\n"
    "lui $2,0x8007\n"
    "addiu $2,$2,4504\n"
    "sll $3,$3,0x2\n"
    "addu $3,$3,$2\n"
    "lw $2,0($3)\n"
    "jr $2\n"
    "nop\n"
    ".end func_800AB2A4\n.set at\n.set reorder\n");
