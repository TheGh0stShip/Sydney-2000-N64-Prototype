/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80072C44\n.ent func_80072C44\n"
    "func_80072C44:\n"
    "sll $2,$2,0x5\n"
    "addu $2,$2,$4\n"
    "sll $3,$2,0x3\n"
    "subu $3,$3,$2\n"
    "and $3,$3,$21\n"
    "srl $4,$3,0xf\n"
    ".end func_80072C44\n.set at\n.set reorder\n");
