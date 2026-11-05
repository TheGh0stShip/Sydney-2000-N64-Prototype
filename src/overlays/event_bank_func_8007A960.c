/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007A960\n.ent func_8007A960\n"
    "func_8007A960:\n"
    "sw $2,3236($3)\n"
    "lbu $5,10960($16)\n"
    "move $4,$0\n"
    "jal func_8009C0D8\n"
    "srl $5,$5,0x5\n"
    "j func_80071914\n"
    "sb $0,3($17)\n"
    ".end func_8007A960\n.set at\n.set reorder\n");
