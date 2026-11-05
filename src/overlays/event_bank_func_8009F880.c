/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8009F880\n.ent func_8009F880\n"
    "func_8009F880:\n"
    "lui $2,0x8010\n"
    "sll $3,$5,0x4\n"
    "subu $3,$3,$5\n"
    "lw $2,-15760($2)\n"
    "sll $3,$3,0x2\n"
    "addu $2,$2,$3\n"
    "sw $0,72($2)\n"
    "lw $17,23712($18)\n"
    "lw $2,180($17)\n"
    "addiu $16,$21,23672\n"
    "lh $4,24($2)\n"
    "lw $2,28($2)\n"
    "jalr $2\n"
    ".end func_8009F880\n.set at\n.set reorder\n");
