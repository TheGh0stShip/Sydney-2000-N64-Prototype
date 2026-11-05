/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80074B9C\n.ent func_80074B9C\n"
    "func_80074B9C:\n"
    ".word 0x14400014\n"
    "nop\n"
    "jal func_800DB124\n"
    "li $4,1\n"
    "jal func_800137FC\n"
    "nop\n"
    "jal func_80014384\n"
    "nop\n"
    "lui $4,0x800f\n"
    "addiu $4,$4,9952\n"
    "lui $2,0x800f\n"
    "lw $5,10052($2)\n"
    "li $2,0x8000\n"
    "lw $7,4($18)\n"
    ".end func_80074B9C\n.set at\n.set reorder\n");
