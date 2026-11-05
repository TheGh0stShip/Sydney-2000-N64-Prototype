/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800745B0\n.ent func_800745B0\n"
    "func_800745B0:\n"
    ".word 0x1062000A\n"
    "li $2,5\n"
    "lbu $3,1556($18)\n"
    ".word 0x14620008\n"
    "lui $2,0x1\n"
    "lbu $2,2822($19)\n"
    "sltiu $2,$2,2\n"
    ".end func_800745B0\n.set at\n.set reorder\n");
