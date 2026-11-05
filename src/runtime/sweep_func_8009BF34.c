/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8009BF34\n.ent func_8009BF34\n"
    "func_8009BF34:\n"
    "addiu $29,$29,-24\n"
    "lui $2,0x8010\n"
    "sw $5,1772($2)\n"
    "lui $2,0x8010\n"
    "lui $3,0x8010\n"
    "sw $4,1764($2)\n"
    "li $2,-1\n"
    "li $4,11520\n"
    "sw $31,16($29)\n"
    "jal func_8009BEE0\n"
    "sw $2,1768($3)\n"
    "lw $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_8009BF34\n.set at\n.set reorder\n");
