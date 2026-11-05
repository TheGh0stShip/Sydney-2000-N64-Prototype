/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80078FAC\n.ent func_80078FAC\n"
    "func_80078FAC:\n"
    "addiu $29,$29,-24\n"
    "lui $4,0x8007\n"
    "addiu $4,$4,25920\n"
    "sw $31,16($29)\n"
    "jal func_800AF064\n"
    "li $5,2\n"
    "lui $4,0x8007\n"
    "addiu $4,$4,25904\n"
    "jal func_800AF064\n"
    "li $5,2\n"
    "lw $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_80078FAC\n.set at\n.set reorder\n");
