/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80075848\n.ent func_80075848\n"
    "func_80075848:\n"
    "jal func_800ADC54\n"
    "sllv $5,$16,$5\n"
    "move $4,$17\n"
    "jal func_800ADC38\n"
    "sb $16,176($4)\n"
    "jal func_80075F20\n"
    "move $4,$18\n"
    "move $4,$18\n"
    ".end func_80075848\n.set at\n.set reorder\n");
