/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007D9C0\n.ent func_8007D9C0\n"
    "func_8007D9C0:\n"
    "andi $2,$18,0xffff\n"
    ".word 0x1440FFF5\n"
    "sh $3,18($17)\n"
    "j func_80074790\n"
    "move $16,$0\n"
    ".end func_8007D9C0\n.set at\n.set reorder\n");
