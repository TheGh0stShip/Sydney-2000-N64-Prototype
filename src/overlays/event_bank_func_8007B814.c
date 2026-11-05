/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007B814\n.ent func_8007B814\n"
    "func_8007B814:\n"
    "li $2,0x8000\n"
    "addu $2,$19,$2\n"
    "li $3,3\n"
    "j func_800726C0\n"
    "sw $3,3220($2)\n"
    ".end func_8007B814\n.set at\n.set reorder\n");
