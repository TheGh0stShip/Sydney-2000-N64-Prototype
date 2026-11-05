/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80077488\n.ent func_80077488\n"
    "func_80077488:\n"
    "sll $2,$2,0x2\n"
    "addu $2,$2,$5\n"
    "sll $2,$2,0x2\n"
    "addu $2,$2,$5\n"
    "sll $2,$2,0x2\n"
    "subu $2,$2,$5\n"
    "sll $2,$2,0x3\n"
    "addu $2,$2,$5\n"
    "sll $6,$2,0x4\n"
    "addu $2,$6,$4\n"
    "sw $31,16($29)\n"
    "lbu $3,2010($2)\n"
    ".end func_80077488\n.set at\n.set reorder\n");
