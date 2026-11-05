/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8012712C\n.ent func_8012712C\n"
    "func_8012712C:\n"
    "addiu $29,$29,-24\n"
    "sw $31,16($29)\n"
    "jal func_8009C690\n"
    "addiu $4,$4,2076\n"
    "lw $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_8012712C\n.set at\n.set reorder\n");
