/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800B633C\n.ent func_800B633C\n"
    "func_800B633C:\n"
    "addiu $29,$29,-24\n"
    "sw $16,16($29)\n"
    "move $16,$4\n"
    "sw $31,20($29)\n"
    "jal func_800D29E0\n"
    "addiu $4,$16,13420\n"
    "jal func_800D1500\n"
    "addiu $4,$16,23512\n"
    "lw $31,20($29)\n"
    "lw $16,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_800B633C\n.set at\n.set reorder\n");
