/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8009D678\n.ent func_8009D678\n"
    "func_8009D678:\n"
    "lw $4,104($16)\n"
    "li $3,32767\n"
    "mult $4,$3\n"
    "move $5,$2\n"
    "move $4,$16\n"
    "mflo $8\n"
    "jal func_8001D640\n"
    "sra $6,$8,0xf\n"
    "lw $2,18064($18)\n"
    "li $3,7680\n"
    "sw $3,24072($18)\n"
    "addiu $2,$2,-1\n"
    "j func_800721CC\n"
    "sw $2,18064($18)\n"
    ".end func_8009D678\n.set at\n.set reorder\n");
