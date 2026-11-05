/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80074A44\n.ent func_80074A44\n"
    "func_80074A44:\n"
    "li $6,7\n"
    "li $2,0x8000\n"
    "addu $2,$18,$2\n"
    "li $3,15\n"
    "sw $3,22864($2)\n"
    "move $2,$6\n"
    ".end func_80074A44\n.set at\n.set reorder\n");
