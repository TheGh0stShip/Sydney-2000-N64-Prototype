/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800E4F50\n.ent func_800E4F50\n"
    "func_800E4F50:\n"
    "addiu $29,$29,-32\n"
    "lui $5,0x8010\n"
    "addiu $5,$5,-11812\n"
    "li $6,1\n"
    "move $7,$6\n"
    "sw $31,24($29)\n"
    "sw $0,16($29)\n"
    "jal func_800B18BC\n"
    "sw $0,20($29)\n"
    "lw $31,24($29)\n"
    "li $2,38\n"
    "jr $31\n"
    "addiu $29,$29,32\n"
    ".end func_800E4F50\n.set at\n.set reorder\n");
