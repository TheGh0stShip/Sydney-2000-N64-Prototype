/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80074C84\n.ent func_80074C84\n"
    "func_80074C84:\n"
    "sltiu $2,$3,31\n"
    ".word 0x10400309\n"
    "lui $2,0x8007\n"
    "addiu $2,$2,2664\n"
    "sll $3,$3,0x2\n"
    "addu $3,$3,$2\n"
    "lw $2,0($3)\n"
    "jr $2\n"
    "nop\n"
    ".end func_80074C84\n.set at\n.set reorder\n");
