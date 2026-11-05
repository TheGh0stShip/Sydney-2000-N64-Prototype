/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80087A50\n.ent func_80087A50\n"
    "func_80087A50:\n"
    "addiu $29,$29,-32\n"
    "move $7,$6\n"
    "li $2,2\n"
    "addiu $4,$4,1116\n"
    "li $6,1\n"
    "sw $31,24($29)\n"
    "jal func_800A9B78\n"
    "sw $2,16($29)\n"
    "lw $31,24($29)\n"
    "jr $31\n"
    "addiu $29,$29,32\n"
    ".end func_80087A50\n.set at\n.set reorder\n");
