/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80074CF4\n.ent func_80074CF4\n"
    "func_80074CF4:\n"
    "jal func_80074034\n"
    "move $4,$18\n"
    "lui $4,0x1\n"
    "ori $4,$4,0x3c8\n"
    "addu $4,$18,$4\n"
    "li $5,10\n"
    "lb $6,2820($16)\n"
    "jal func_8009B80C\n"
    ".end func_80074CF4\n.set at\n.set reorder\n");
