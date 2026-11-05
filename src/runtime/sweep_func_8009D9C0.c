/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8009D9C0\n.ent func_8009D9C0\n"
    "func_8009D9C0:\n"
    "addiu $29,$29,-24\n"
    "sw $16,16($29)\n"
    "move $16,$4\n"
    "li $5,8\n"
    "li $6,5\n"
    "sw $31,20($29)\n"
    "jal func_800E5830\n"
    "li $7,6\n"
    "sw $0,212($16)\n"
    "sw $0,260($16)\n"
    "lw $31,20($29)\n"
    "lw $16,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_8009D9C0\n.set at\n.set reorder\n");
