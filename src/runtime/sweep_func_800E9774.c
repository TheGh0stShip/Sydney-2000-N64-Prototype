/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800E9774\n.ent func_800E9774\n"
    "func_800E9774:\n"
    "addiu $29,$29,-24\n"
    "li $2,-1\n"
    "sw $31,16($29)\n"
    "jal func_800E9744\n"
    "sw $2,29364($4)\n"
    "lw $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_800E9774\n.set at\n.set reorder\n");
