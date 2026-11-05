/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80126DF4\n.ent func_80126DF4\n"
    "func_80126DF4:\n"
    "addiu $29,$29,-24\n"
    "addiu $4,$4,1292\n"
    "sw $31,16($29)\n"
    "lw $2,4($4)\n"
    "beqz $2,L_80126E14\n"
    "nop\n"
    "jal func_800AC334\n"
    "nop\n"
    "L_80126E14:\n"
    "lw $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_80126DF4\n.set at\n.set reorder\n");
