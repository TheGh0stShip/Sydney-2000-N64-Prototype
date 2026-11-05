/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800E79A8\n.ent func_800E79A8\n"
    "func_800E79A8:\n"
    "move $5,$20\n"
    "move $6,$21\n"
    "jal func_800B9964\n"
    "move $7,$19\n"
    "jal func_8007D6D8\n"
    "move $4,$16\n"
    "lui $2,0x800f\n"
    "lw $2,10024($2)\n"
    ".word 0x10400094\n"
    "move $5,$0\n"
    "lui $3,0x1\n"
    "lw $2,1108($16)\n"
    "ori $3,$3,0x2bff\n"
    "addiu $2,$2,-256\n"
    ".end func_800E79A8\n.set at\n.set reorder\n");
