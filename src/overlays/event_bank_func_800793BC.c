/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800793BC\n.ent func_800793BC\n"
    "func_800793BC:\n"
    "move $3,$0\n"
    "lbu $2,426($4)\n"
    "xori $2,$2,0x4\n"
    "sltu $3,$3,$2\n"
    "beqz $3,L_800793DC\n"
    "nop\n"
    "jal func_8008382C\n"
    "nop\n"
    "L_800793DC:\n"
    "lw $31,20($29)\n"
    "lw $16,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_800793BC\n.set at\n.set reorder\n");
