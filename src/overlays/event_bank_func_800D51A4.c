/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800D51A4\n.ent func_800D51A4\n"
    "func_800D51A4:\n"
    "li $3,1\n"
    "sw $3,19796($17)\n"
    "sll $2,$2,0x18\n"
    "sra $2,$2,0x18\n"
    "sll $4,$4,0x18\n"
    "sra $4,$4,0x18\n"
    "subu $2,$2,$4\n"
    "sh $2,19714($17)\n"
    "lw $31,36($29)\n"
    "lw $18,32($29)\n"
    "lw $17,28($29)\n"
    "lw $16,24($29)\n"
    "jr $31\n"
    "addiu $29,$29,40\n"
    ".end func_800D51A4\n.set at\n.set reorder\n");
