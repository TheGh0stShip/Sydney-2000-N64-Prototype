/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800957A4\n.ent func_800957A4\n"
    "func_800957A4:\n"
    "addiu $29,$29,-24\n"
    "addiu $4,$4,29688\n"
    "sw $31,16($29)\n"
    "jal func_800A9BE8\n"
    "li $5,7\n"
    "lw $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_800957A4\n.set at\n.set reorder\n");
