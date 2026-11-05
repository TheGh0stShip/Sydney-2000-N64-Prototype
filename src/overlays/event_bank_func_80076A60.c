/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076A60\n.ent func_80076A60\n"
    "func_80076A60:\n"
    "sw $2,2228($5)\n"
    "sw $4,2232($3)\n"
    "lbu $2,0($10)\n"
    "move $9,$3\n"
    "sb $2,2008($6)\n"
    "lbu $2,1($10)\n"
    "move $4,$3\n"
    "sb $2,2009($7)\n"
    "lbu $2,1($10)\n"
    "addiu $4,$4,1988\n"
    "andi $2,$2,0x7\n"
    "sb $2,2220($8)\n"
    "sb $11,2010($9)\n"
    "sb $17,2011($3)\n"
    ".end func_80076A60\n.set at\n.set reorder\n");
