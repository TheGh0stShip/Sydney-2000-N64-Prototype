/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80083174\n.ent func_80083174\n"
    "func_80083174:\n"
    "lui $5,0x4283\n"
    "ori $5,$5,0x1168\n"
    "jal func_80076884\n"
    "move $4,$17\n"
    "lbu $16,1556($17)\n"
    ".end func_80083174\n.set at\n.set reorder\n");
