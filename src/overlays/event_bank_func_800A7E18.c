/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800A7E18\n.ent func_800A7E18\n"
    "func_800A7E18:\n"
    "addiu $29,$29,-24\n"
    "sw $16,16($29)\n"
    "move $16,$4\n"
    "li $2,1\n"
    "addiu $4,$16,29936\n"
    "sw $31,20($29)\n"
    "jal func_800CEE04\n"
    "sw $2,31948($16)\n"
    "jal func_80097504\n"
    "addiu $4,$16,13804\n"
    "lw $31,20($29)\n"
    "lw $16,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_800A7E18\n.set at\n.set reorder\n");
