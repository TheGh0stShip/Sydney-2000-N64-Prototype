/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007283C\n.ent func_8007283C\n"
    "func_8007283C:\n"
    "sw $2,16($29)\n"
    "jal func_8001D5D8\n"
    "sw $0,20($29)\n"
    "move $4,$19\n"
    "lui $16,0x8010\n"
    "lw $2,-15760($16)\n"
    "move $6,$0\n"
    "lw $5,3388($2)\n"
    "jal func_80073890\n"
    "move $7,$6\n"
    "lw $2,-15760($16)\n"
    "lw $4,3388($2)\n"
    "jal func_8001CCF0\n"
    "nop\n"
    ".end func_8007283C\n.set at\n.set reorder\n");
