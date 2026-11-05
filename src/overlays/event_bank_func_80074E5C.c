/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80074E5C\n.ent func_80074E5C\n"
    "func_80074E5C:\n"
    "sw $2,1216($18)\n"
    "lbu $3,1556($18)\n"
    "sltiu $2,$3,6\n"
    ".word 0x10400018\n"
    "lui $2,0x8007\n"
    "addiu $2,$2,2816\n"
    "sll $3,$3,0x2\n"
    "addu $3,$3,$2\n"
    "lw $2,0($3)\n"
    ".end func_80074E5C\n.set at\n.set reorder\n");
