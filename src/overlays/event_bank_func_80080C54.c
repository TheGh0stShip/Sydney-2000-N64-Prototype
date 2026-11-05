/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80080C54\n.ent func_80080C54\n"
    "func_80080C54:\n"
    "lw $7,1772($18)\n"
    "mtc1 $0,$f20\n"
    "jal func_800BAA18\n"
    "addiu $6,$29,184\n"
    "j func_80077A58\n"
    "li $2,72\n"
    ".end func_80080C54\n.set at\n.set reorder\n");
