/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80083624\n.ent func_80083624\n"
    "func_80083624:\n"
    "jal func_800D33A0\n"
    "li $7,-1\n"
    "move $4,$19\n"
    "li $5,41\n"
    "move $6,$0\n"
    "jal func_8007676C\n"
    "move $7,$6\n"
    "lbu $5,1554($19)\n"
    ".end func_80083624\n.set at\n.set reorder\n");
