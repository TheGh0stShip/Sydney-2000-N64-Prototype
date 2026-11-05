/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800B4750\n.ent func_800B4750\n"
    "func_800B4750:\n"
    "addiu $29,$29,-24\n"
    "lui $4,0x800f\n"
    "addiu $4,$4,9972\n"
    "sw $31,16($29)\n"
    "jal func_800ABA54\n"
    "li $5,2\n"
    "lui $4,0x800f\n"
    "addiu $4,$4,9952\n"
    "jal func_800AB48C\n"
    "li $5,2\n"
    "lw $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_800B4750\n.set at\n.set reorder\n");
