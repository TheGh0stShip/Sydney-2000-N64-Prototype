/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800971BC\n.ent func_800971BC\n"
    "func_800971BC:\n"
    "addiu $29,$29,-40\n"
    "sw $31,32($29)\n"
    "sw $17,28($29)\n"
    "sw $16,24($29)\n"
    "lw $3,16($5)\n"
    "sltiu $2,$3,19\n"
    ".word 0x1040004B\n"
    "move $17,$4\n"
    "lui $2,0x8007\n"
    "addiu $2,$2,4112\n"
    "sll $3,$3,0x2\n"
    "addu $3,$3,$2\n"
    ".end func_800971BC\n.set at\n.set reorder\n");
