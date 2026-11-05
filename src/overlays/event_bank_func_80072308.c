/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80072308\n.ent func_80072308\n"
    "func_80072308:\n"
    "addu $4,$3,$4\n"
    "lw $3,200($19)\n"
    "lw $2,180($3)\n"
    "li $5,2\n"
    "lh $4,8($2)\n"
    "lw $2,12($2)\n"
    "jalr $2\n"
    "addu $4,$3,$4\n"
    "lui $4,0x800f\n"
    ".end func_80072308\n.set at\n.set reorder\n");
