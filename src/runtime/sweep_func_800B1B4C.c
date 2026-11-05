/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800B1B4C\n.ent func_800B1B4C\n"
    "func_800B1B4C:\n"
    "addiu $29,$29,-24\n"
    "sw $31,20($29)\n"
    "sw $16,16($29)\n"
    "lw $2,220($4)\n"
    "lw $16,28($2)\n"
    "jal func_800B31EC\n"
    "move $4,$0\n"
    "lw $31,20($29)\n"
    "move $2,$16\n"
    "lw $16,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_800B1B4C\n.set at\n.set reorder\n");
