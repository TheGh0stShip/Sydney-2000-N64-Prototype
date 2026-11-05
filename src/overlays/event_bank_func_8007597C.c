/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007597C\n.ent func_8007597C\n"
    "func_8007597C:\n"
    "li $3,0x8000\n"
    "addu $3,$20,$3\n"
    "lui $2,0x8010\n"
    "lw $4,-15760($2)\n"
    "li $2,15\n"
    "sw $0,3400($5)\n"
    "sw $2,22864($3)\n"
    ".end func_8007597C\n.set at\n.set reorder\n");
