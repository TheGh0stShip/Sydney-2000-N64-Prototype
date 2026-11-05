/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076854\n.ent func_80076854\n"
    "func_80076854:\n"
    "jal func_800AACB0\n"
    "li $6,1\n"
    "move $18,$0\n"
    "move $20,$17\n"
    ".end func_80076854\n.set at\n.set reorder\n");
