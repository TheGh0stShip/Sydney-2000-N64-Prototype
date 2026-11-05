/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80075C38\n.ent func_80075C38\n"
    "func_80075C38:\n"
    "li $2,130\n"
    "jal func_800D3FD0\n"
    "sw $2,20($29)\n"
    "lui $2,0x1\n"
    "lui $3,0x8010\n"
    "lw $3,-15760($3)\n"
    "addu $2,$20,$2\n"
    ".end func_80075C38\n.set at\n.set reorder\n");
