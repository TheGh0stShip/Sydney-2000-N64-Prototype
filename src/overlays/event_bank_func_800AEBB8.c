/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800AEBB8\n.ent func_800AEBB8\n"
    "func_800AEBB8:\n"
    "beqz $2,L_800AEBD4\n"
    "lui $4,0x800f\n"
    "addiu $4,$4,15296\n"
    "li $5,180\n"
    "move $6,$0\n"
    "jal func_800C0110\n"
    "move $7,$6\n"
    "L_800AEBD4:\n"
    "lw $31,32($29)\n"
    "lw $17,28($29)\n"
    "lw $16,24($29)\n"
    "jr $31\n"
    "addiu $29,$29,40\n"
    ".end func_800AEBB8\n.set at\n.set reorder\n");
