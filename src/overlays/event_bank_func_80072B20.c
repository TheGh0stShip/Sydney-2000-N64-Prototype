/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80072B20\n.ent func_80072B20\n"
    "func_80072B20:\n"
    "lw $5,10004($20)\n"
    "addiu $8,$8,16216\n"
    "sw $0,16($29)\n"
    "sll $2,$5,0x2\n"
    "addu $2,$2,$5\n"
    "sll $3,$2,0x4\n"
    "subu $3,$3,$2\n"
    "sll $3,$3,0x5\n"
    "addu $3,$3,$5\n"
    "sll $2,$3,0x3\n"
    "subu $2,$2,$3\n"
    "and $2,$2,$21\n"
    "sw $2,10004($20)\n"
    "srl $2,$2,0x1c\n"
    ".end func_80072B20\n.set at\n.set reorder\n");
