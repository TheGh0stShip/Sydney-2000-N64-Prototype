/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800812EC\n.ent func_800812EC\n"
    "func_800812EC:\n"
    "li $5,13\n"
    "li $6,1\n"
    "move $7,$17\n"
    "jal func_800BBD78\n"
    "sw $2,16($29)\n"
    "lw $31,32($29)\n"
    "lw $17,28($29)\n"
    "lw $16,24($29)\n"
    "jr $31\n"
    "addiu $29,$29,40\n"
    ".end func_800812EC\n.set at\n.set reorder\n");
