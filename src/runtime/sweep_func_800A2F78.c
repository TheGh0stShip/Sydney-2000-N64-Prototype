/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800A2F78\n.ent func_800A2F78\n"
    "func_800A2F78:\n"
    "addiu $29,$29,-24\n"
    "lui $4,0x800f\n"
    "addiu $4,$4,7044\n"
    "sw $31,16($29)\n"
    "jal func_8001E0FC\n"
    "li $5,2\n"
    "lui $4,0x800f\n"
    "addiu $4,$4,6880\n"
    "addiu $4,$4,1\n"
    "jal func_8001D870\n"
    "move $5,$0\n"
    "lw $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_800A2F78\n.set at\n.set reorder\n");
