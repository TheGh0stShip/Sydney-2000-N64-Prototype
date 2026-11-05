/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076F6C\n.ent func_80076F6C\n"
    "func_80076F6C:\n"
    "sll $2,$2,0x3\n"
    "addu $2,$2,$8\n"
    "sll $2,$2,0x4\n"
    "addu $2,$2,$18\n"
    "sll $4,$4,0x3\n"
    "sw $5,5104($6)\n"
    "xori $6,$11,0x1\n"
    "lbu $3,3364($9)\n"
    "lwc1 $f0,2364($2)\n"
    "sll $3,$3,0x2\n"
    "addu $3,$3,$4\n"
    "addu $3,$18,$3\n"
    "addu $3,$3,$10\n"
    ".end func_80076F6C\n.set at\n.set reorder\n");
