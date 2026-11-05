/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076FDC\n.ent func_80076FDC\n"
    "func_80076FDC:\n"
    ".word 0x506D0013\n"
    "andi $7,$6,0xff\n"
    "lbu $2,1556($18)\n"
    "sltiu $2,$2,2\n"
    ".word 0x1040006D\n"
    ".end func_80076FDC\n.set at\n.set reorder\n");
