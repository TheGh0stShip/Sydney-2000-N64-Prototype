/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80072874\n.ent func_80072874\n"
    "func_80072874:\n"
    "lw $2,-15760($16)\n"
    "lui $3,0x8007\n"
    "lw $2,3388($2)\n"
    "addiu $3,$3,15152\n"
    "sll $2,$2,0x2\n"
    "addu $2,$2,$3\n"
    "lw $2,0($2)\n"
    "sw $2,5028($19)\n"
    "move $18,$0\n"
    "addiu $21,$29,56\n"
    ".end func_80072874\n.set at\n.set reorder\n");
