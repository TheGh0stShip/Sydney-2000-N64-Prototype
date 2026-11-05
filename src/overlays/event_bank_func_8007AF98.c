/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007AF98\n.ent func_8007AF98\n"
    "func_8007AF98:\n"
    "move $5,$19\n"
    "jal func_800AACB0\n"
    "move $6,$0\n"
    "li $2,1\n"
    "j func_80072930\n"
    "sw $2,172($19)\n"
    ".end func_8007AF98\n.set at\n.set reorder\n");
