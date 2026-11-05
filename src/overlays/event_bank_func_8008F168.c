/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8008F168\n.ent func_8008F168\n"
    "func_8008F168:\n"
    "addiu $29,$29,-24\n"
    "sw $31,16($29)\n"
    "lw $2,2564($2)\n"
    "beqz $2,L_8008F188\n"
    "nop\n"
    "lui $4,0x800f\n"
    "jal func_800C0110\n"
    "addiu $4,$4,15296\n"
    "L_8008F188:\n"
    "lw $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_8008F168\n.set at\n.set reorder\n");
