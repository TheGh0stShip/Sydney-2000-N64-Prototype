/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800839DC\n.ent func_800839DC\n"
    "func_800839DC:\n"
    "sltiu $2,$3,6\n"
    ".word 0x10400022\n"
    "lui $2,0x8007\n"
    "addiu $2,$2,4440\n"
    "sll $3,$3,0x2\n"
    "addu $3,$3,$2\n"
    "lw $2,0($3)\n"
    "jr $2\n"
    "nop\n"
    ".end func_800839DC\n.set at\n.set reorder\n");
