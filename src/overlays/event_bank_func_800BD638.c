/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800BD638\n.ent func_800BD638\n"
    "func_800BD638:\n"
    "jal func_800720A8\n"
    "sb $2,17908($19)\n"
    "lw $2,18712($19)\n"
    "bne $2,$16,L_800BD654\n"
    "addiu $4,$19,4552\n"
    "j func_80071098\n"
    "li $5,8\n"
    "L_800BD654:\n"
    "j func_800710B4\n"
    "li $5,13\n"
    ".end func_800BD638\n.set at\n.set reorder\n");
