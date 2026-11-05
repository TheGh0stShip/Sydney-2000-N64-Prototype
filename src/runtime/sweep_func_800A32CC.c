/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800A32CC\n.ent func_800A32CC\n"
    "func_800A32CC:\n"
    "addiu $29,$29,-24\n"
    "sw $31,16($29)\n"
    "jal func_8001D550\n"
    "li $5,3\n"
    "lw $31,16($29)\n"
    "li $2,1\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_800A32CC\n.set at\n.set reorder\n");
