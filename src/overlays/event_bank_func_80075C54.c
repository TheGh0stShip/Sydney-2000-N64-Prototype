/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80075C54\n.ent func_80075C54\n"
    "func_80075C54:\n"
    "sw $0,3396($2)\n"
    "lw $3,2560($3)\n"
    "sltiu $2,$3,7\n"
    ".word 0x1040000D\n"
    "lui $2,0x8007\n"
    ".end func_80075C54\n.set at\n.set reorder\n");
