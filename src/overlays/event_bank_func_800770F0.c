/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800770F0\n.ent func_800770F0\n"
    "func_800770F0:\n"
    "lbu $2,1556($18)\n"
    "sltiu $2,$2,2\n"
    ".word 0x1040001E\n"
    "andi $2,$19,0xff\n"
    "sll $16,$2,0x1\n"
    "addu $16,$16,$2\n"
    "sll $16,$16,0x2\n"
    "addu $16,$16,$2\n"
    "sll $16,$16,0x2\n"
    "addu $16,$16,$2\n"
    "sll $16,$16,0x2\n"
    "subu $16,$16,$2\n"
    ".end func_800770F0\n.set at\n.set reorder\n");
