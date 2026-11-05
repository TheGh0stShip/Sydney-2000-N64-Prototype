/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80074AE4\n.ent func_80074AE4\n"
    "func_80074AE4:\n"
    "move $4,$18\n"
    "lbu $2,3($16)\n"
    "andi $2,$2,0xa\n"
    ".word 0x10400024\n"
    "li $2,0x8000\n"
    "addu $2,$18,$2\n"
    "sw $0,22864($2)\n"
    "jal func_80072EE4\n"
    "move $4,$18\n"
    "j func_80071828\n"
    ".end func_80074AE4\n.set at\n.set reorder\n");
