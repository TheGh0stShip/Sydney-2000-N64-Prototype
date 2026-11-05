/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8009576C\n.ent func_8009576C\n"
    "func_8009576C:\n"
    "addiu $29,$29,-24\n"
    "sw $16,16($29)\n"
    "move $16,$4\n"
    "sw $31,20($29)\n"
    "jal func_800D29E0\n"
    "addiu $4,$16,12964\n"
    "jal func_800D29E0\n"
    "addiu $4,$16,14364\n"
    "jal func_800D29E0\n"
    "addiu $4,$16,15764\n"
    "lw $31,20($29)\n"
    "lw $16,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_8009576C\n.set at\n.set reorder\n");
