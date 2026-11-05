/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80075714\n.ent func_80075714\n"
    "func_80075714:\n"
    "sll $2,$2,0x5\n"
    "addu $2,$2,$8\n"
    "sll $3,$2,0x3\n"
    "subu $3,$3,$2\n"
    "and $3,$3,$9\n"
    "sw $3,5104($17)\n"
    ".end func_80075714\n.set at\n.set reorder\n");
