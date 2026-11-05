/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80082FFC\n.ent func_80082FFC\n"
    "func_80082FFC:\n"
    "sb $2,1548($18)\n"
    "andi $2,$2,0xff\n"
    ".end func_80082FFC\n.set at\n.set reorder\n");
