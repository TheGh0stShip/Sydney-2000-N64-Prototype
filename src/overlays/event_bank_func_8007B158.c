/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007B158\n.ent func_8007B158\n"
    "func_8007B158:\n"
    "move $4,$16\n"
    "move $17,$2\n"
    "move $5,$17\n"
    "jal func_8001D640\n"
    "move $6,$0\n"
    "move $4,$16\n"
    "lw $3,104($4)\n"
    "li $2,24575\n"
    "mult $3,$2\n"
    ".end func_8007B158\n.set at\n.set reorder\n");
