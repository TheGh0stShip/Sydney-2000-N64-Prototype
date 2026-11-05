/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007DA0C\n.ent func_8007DA0C\n"
    "func_8007DA0C:\n"
    "sh $0,16($17)\n"
    "sh $0,18($17)\n"
    "sw $0,12($17)\n"
    "sw $0,0($17)\n"
    "move $16,$0\n"
    "li $19,0x8a20\n"
    "li $18,1\n"
    "lui $1,0x8007\n"
    ".end func_8007DA0C\n.set at\n.set reorder\n");
