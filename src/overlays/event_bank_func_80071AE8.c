/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80071AE8\n.ent func_80071AE8\n"
    "func_80071AE8:\n"
    "and $3,$3,$8\n"
    "srl $4,$3,0xf\n"
    "andi $2,$23,0xff\n"
    "sll $16,$2,0x1\n"
    "addu $16,$16,$2\n"
    "sll $16,$16,0x3\n"
    "addu $16,$16,$2\n"
    "sll $16,$16,0x2\n"
    "addu $16,$16,$2\n"
    ".end func_80071AE8\n.set at\n.set reorder\n");
