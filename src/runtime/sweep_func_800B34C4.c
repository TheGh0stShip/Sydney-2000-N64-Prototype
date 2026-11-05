/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800B34C4\n.ent func_800B34C4\n"
    "func_800B34C4:\n"
    "addiu $29,$29,-24\n"
    "sw $31,16($29)\n"
    "lhu $2,212($4)\n"
    "andi $2,$2,0x4\n"
    "beqz $2,L_800B34E0\n"
    "li $5,1\n"
    "move $5,$0\n"
    "L_800B34E0:\n"
    "jal func_800B2158\n"
    "nop\n"
    "lw $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_800B34C4\n.set at\n.set reorder\n");
