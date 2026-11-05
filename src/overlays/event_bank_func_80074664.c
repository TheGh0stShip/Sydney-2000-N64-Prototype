/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80074664\n.ent func_80074664\n"
    "func_80074664:\n"
    "move $6,$0\n"
    "jal func_8001D4B8\n"
    "move $7,$6\n"
    "lw $4,104($16)\n"
    "li $3,32767\n"
    "mult $4,$3\n"
    "move $5,$2\n"
    "move $4,$16\n"
    "mflo $8\n"
    "jal func_8001D640\n"
    "sra $6,$8,0xf\n"
    ".end func_80074664\n.set at\n.set reorder\n");
