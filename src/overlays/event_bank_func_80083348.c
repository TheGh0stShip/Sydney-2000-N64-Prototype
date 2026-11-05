/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80083348\n.ent func_80083348\n"
    "func_80083348:\n"
    "jal func_8009B4D4\n"
    "move $7,$16\n"
    ".word 0x10400011\n"
    "li $5,220\n"
    "lui $16,0x800f\n"
    "addiu $16,$16,6880\n"
    "move $4,$16\n"
    "move $6,$0\n"
    "jal func_8001D4B8\n"
    "li $7,1\n"
    "lw $4,104($16)\n"
    "li $3,32767\n"
    "mult $4,$3\n"
    ".end func_80083348\n.set at\n.set reorder\n");
