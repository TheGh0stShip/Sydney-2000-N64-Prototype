/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80077088\n.ent func_80077088\n"
    "func_80077088:\n"
    "sll $2,$6,0x2\n"
    "addiu $4,$29,24\n"
    "addu $2,$4,$2\n"
    "negu $3,$5\n"
    "sw $3,0($2)\n"
    "sll $2,$7,0x2\n"
    "addu $4,$4,$2\n"
    ".end func_80077088\n.set at\n.set reorder\n");
