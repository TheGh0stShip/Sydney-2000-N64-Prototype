/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800E9744\n.ent func_800E9744\n"
    "func_800E9744:\n"
    "addiu $29,$29,-24\n"
    "sw $16,16($29)\n"
    "addiu $16,$4,27656\n"
    "sw $31,20($29)\n"
    "jal func_800AC334\n"
    "move $4,$16\n"
    "jal func_800ADC1C\n"
    "move $4,$16\n"
    "lw $31,20($29)\n"
    "lw $16,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_800E9744\n.set at\n.set reorder\n");
