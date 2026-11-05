/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076654\n.ent func_80076654\n"
    "func_80076654:\n"
    "move $4,$19\n"
    ".word 0x1440FFB2\n"
    "li $2,4\n"
    "lw $3,-15760($16)\n"
    "lw $4,2560($3)\n"
    ".word 0x1482000C\n"
    "li $2,2\n"
    "lw $3,2564($3)\n"
    ".end func_80076654\n.set at\n.set reorder\n");
