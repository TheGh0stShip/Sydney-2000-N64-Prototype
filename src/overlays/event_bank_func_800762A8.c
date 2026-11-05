/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800762A8\n.ent func_800762A8\n"
    "func_800762A8:\n"
    "jal func_800AC25C\n"
    "move $7,$0\n"
    "lw $2,1564($18)\n"
    "beqz $2,L_800762D0\n"
    "lui $16,0x1\n"
    "lui $4,0x800f\n"
    "addiu $4,$4,10072\n"
    "jal func_800AA658\n"
    "addiu $5,$18,1564\n"
    "lui $16,0x1\n"
    "L_800762D0:\n"
    "ori $16,$16,0x3c8\n"
    "addu $16,$18,$16\n"
    ".end func_800762A8\n.set at\n.set reorder\n");
