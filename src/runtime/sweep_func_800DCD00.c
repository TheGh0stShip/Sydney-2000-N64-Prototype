/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800DCD00\n.ent func_800DCD00\n"
    "func_800DCD00:\n"
    "addiu $29,$29,-24\n"
    "sw $16,16($29)\n"
    "move $16,$4\n"
    "li $5,107\n"
    "li $6,7\n"
    "sw $31,20($29)\n"
    "jal func_800AC25C\n"
    "move $7,$0\n"
    "sh $0,468($16)\n"
    "lw $31,20($29)\n"
    "lw $16,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_800DCD00\n.set at\n.set reorder\n");
