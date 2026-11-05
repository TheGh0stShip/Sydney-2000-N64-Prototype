/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800749F4\n.ent func_800749F4\n"
    "func_800749F4:\n"
    "lui $3,0x1\n"
    "addu $3,$18,$3\n"
    "lbu $2,2820($3)\n"
    "addiu $2,$2,1\n"
    "sb $2,2820($3)\n"
    "lui $3,0x8010\n"
    "lw $3,-15760($3)\n"
    "lbu $3,2572($3)\n"
    "andi $2,$2,0xff\n"
    "sltu $2,$2,$3\n"
    ".end func_800749F4\n.set at\n.set reorder\n");
