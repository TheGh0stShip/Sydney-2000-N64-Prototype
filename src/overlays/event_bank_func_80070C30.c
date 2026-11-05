/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80070C30\n.ent func_80070C30\n"
    "func_80070C30:\n"
    "lw $4,184($21)\n"
    "jal func_8007E918\n"
    "addiu $7,$21,2936\n"
    "lw $3,184($21)\n"
    "lw $2,180($3)\n"
    "move $5,$21\n"
    "lh $4,16($2)\n"
    ".end func_80070C30\n.set at\n.set reorder\n");
