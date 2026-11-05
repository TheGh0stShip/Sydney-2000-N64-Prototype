/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800761D4\n.ent func_800761D4\n"
    "func_800761D4:\n"
    "lui $5,0x800f\n"
    "lw $4,5104($5)\n"
    "ori $6,$6,0xffff\n"
    "sll $3,$4,0x2\n"
    "addu $3,$3,$4\n"
    "sll $2,$3,0x4\n"
    "subu $2,$2,$3\n"
    "sll $2,$2,0x5\n"
    "addu $2,$2,$4\n"
    "sll $3,$2,0x3\n"
    "subu $3,$3,$2\n"
    "and $3,$3,$6\n"
    ".end func_800761D4\n.set at\n.set reorder\n");
