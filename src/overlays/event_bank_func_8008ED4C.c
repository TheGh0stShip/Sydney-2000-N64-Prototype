/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8008ED4C\n.ent func_8008ED4C\n"
    "func_8008ED4C:\n"
    "addiu $29,$29,-24\n"
    "lui $4,0x8007\n"
    "addiu $4,$4,30464\n"
    "sw $31,16($29)\n"
    "jal func_800AF064\n"
    "li $5,2\n"
    "lui $4,0x8007\n"
    "addiu $4,$4,29712\n"
    "jal func_800AF064\n"
    "li $5,2\n"
    "lw $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_8008ED4C\n.set at\n.set reorder\n");
