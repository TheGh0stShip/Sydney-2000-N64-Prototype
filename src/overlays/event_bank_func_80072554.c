/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80072554\n.ent func_80072554\n"
    "func_80072554:\n"
    "addu $4,$19,$4\n"
    "sll $3,$5,0x2\n"
    "addu $3,$3,$5\n"
    "sll $2,$3,0x4\n"
    "subu $2,$2,$3\n"
    ".end func_80072554\n.set at\n.set reorder\n");
