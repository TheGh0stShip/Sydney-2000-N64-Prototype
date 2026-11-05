/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076F3C\n.ent func_80076F3C\n"
    "func_80076F3C:\n"
    "addu $2,$2,$4\n"
    "sll $5,$2,0x3\n"
    "subu $5,$5,$2\n"
    "and $5,$5,$7\n"
    "sll $4,$8,0x1\n"
    "addu $4,$4,$8\n"
    "sll $2,$4,0x2\n"
    "addu $2,$2,$8\n"
    "sll $2,$2,0x2\n"
    "addu $2,$2,$8\n"
    "sll $2,$2,0x2\n"
    "subu $2,$2,$8\n"
    ".end func_80076F3C\n.set at\n.set reorder\n");
