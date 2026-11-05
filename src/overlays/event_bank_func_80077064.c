/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80077064\n.ent func_80077064\n"
    "func_80077064:\n"
    "addu $3,$3,$7\n"
    "sll $3,$3,0x3\n"
    "addu $2,$2,$3\n"
    ".end func_80077064\n.set at\n.set reorder\n");
