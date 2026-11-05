/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076FB8\n.ent func_80076FB8\n"
    "func_80076FB8:\n"
    "addu $2,$18,$2\n"
    "addu $2,$2,$10\n"
    "sb $3,3364($9)\n"
    "sw $12,3268($2)\n"
    "lbu $4,3364($9)\n"
    "li $2,3\n"
    "andi $3,$4,0xff\n"
    ".word 0x10620014\n"
    "srl $20,$5,0x1e\n"
    ".end func_80076FB8\n.set at\n.set reorder\n");
