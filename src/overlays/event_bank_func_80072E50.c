/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80072E50\n.ent func_80072E50\n"
    "func_80072E50:\n"
    "lui $2,0x8007\n"
    "addiu $30,$2,16248\n"
    "lui $2,0x8007\n"
    "addiu $23,$2,16256\n"
    "li $22,3\n"
    "andi $16,$18,0xff\n"
    "sltiu $2,$16,3\n"
    ".word 0x10400072\n"
    "sll $4,$16,0x1\n"
    "addu $4,$4,$16\n"
    "sll $4,$4,0x3\n"
    "addu $4,$4,$16\n"
    "sll $4,$4,0x2\n"
    "addu $4,$4,$16\n"
    ".end func_80072E50\n.set at\n.set reorder\n");
