/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800A0EDC\n.ent func_800A0EDC\n"
    "func_800A0EDC:\n"
    "addiu $29,$29,-24\n"
    "sw $16,16($29)\n"
    "move $16,$4\n"
    "sw $31,20($29)\n"
    "jal func_8009BD50\n"
    "li $4,5\n"
    "move $4,$16\n"
    "li $2,-1\n"
    "jal func_800739B0\n"
    "sw $2,24112($16)\n"
    "jal func_800AC334\n"
    "addiu $4,$16,23456\n"
    "jal func_800D771C\n"
    ".end func_800A0EDC\n.set at\n.set reorder\n");
