/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80075F84\n.ent func_80075F84\n"
    "func_80075F84:\n"
    "andi $2,$18,0xffff\n"
    ".word 0x1440FFF5\n"
    "sh $3,18($17)\n"
    "j func_80072C84\n"
    ".end func_80075F84\n.set at\n.set reorder\n");
