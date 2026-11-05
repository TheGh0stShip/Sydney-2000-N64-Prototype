/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80126D84\n.ent func_80126D84\n"
    "func_80126D84:\n"
    "addiu $29,$29,-24\n"
    "sw $31,16($29)\n"
    "lbu $3,426($4)\n"
    "li $2,4\n"
    "beq $3,$2,L_80126DA4\n"
    "addiu $4,$4,1048\n"
    "jal func_800A9BE8\n"
    "li $5,6\n"
    "L_80126DA4:\n"
    "lw $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_80126D84\n.set at\n.set reorder\n");
