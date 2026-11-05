/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8009BDF4\n.ent func_8009BDF4\n"
    "func_8009BDF4:\n"
    "addiu $29,$29,-24\n"
    "addiu $4,$4,32228\n"
    "sw $31,16($29)\n"
    "jal func_800A9BE8\n"
    "li $5,11\n"
    "lw $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_8009BDF4\n.set at\n.set reorder\n");
