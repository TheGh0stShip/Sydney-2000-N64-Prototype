/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007C738\n.ent func_8007C738\n"
    "func_8007C738:\n"
    "lw $5,3284($8)\n"
    "li $2,1\n"
    "jal func_80077EEC\n"
    "sb $2,3288($8)\n"
    "jal func_8007755C\n"
    "move $4,$19\n"
    "j func_80073CC4\n"
    "nop\n"
    ".end func_8007C738\n.set at\n.set reorder\n");
