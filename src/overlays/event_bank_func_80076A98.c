/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076A98\n.ent func_80076A98\n"
    "func_80076A98:\n"
    "lbu $5,1($10)\n"
    "lb $6,0($10)\n"
    "jal func_8009A828\n"
    "addiu $19,$19,1\n"
    "addiu $16,$16,1584\n"
    "addu $4,$18,$16\n"
    "move $5,$18\n"
    "move $6,$17\n"
    ".end func_80076A98\n.set at\n.set reorder\n");
