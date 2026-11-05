/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800CCAE0\n.ent func_800CCAE0\n"
    "func_800CCAE0:\n"
    "addiu $29,$29,-24\n"
    "sw $16,16($29)\n"
    "sw $31,20($29)\n"
    "jal func_8001457C\n"
    "move $16,$4\n"
    "jal func_800ADC38\n"
    "addiu $4,$16,240\n"
    "lw $31,20($29)\n"
    "lw $16,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_800CCAE0\n.set at\n.set reorder\n");
