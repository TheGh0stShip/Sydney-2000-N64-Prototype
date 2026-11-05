/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8009F84C\n.ent func_8009F84C\n"
    "func_8009F84C:\n"
    "addiu $29,$29,-24\n"
    "sw $16,16($29)\n"
    "sw $31,20($29)\n"
    "jal func_80014480\n"
    "move $16,$4\n"
    "jal func_80014480\n"
    "addiu $4,$16,476\n"
    "jal func_80014480\n"
    "addiu $4,$16,700\n"
    "lw $31,20($29)\n"
    "lw $16,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_8009F84C\n.set at\n.set reorder\n");
