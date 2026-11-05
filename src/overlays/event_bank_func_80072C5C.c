/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80072C5C\n.ent func_80072C5C\n"
    "func_80072C5C:\n"
    "andi $2,$18,0xff\n"
    "sll $16,$2,0x1\n"
    ".end func_80072C5C\n.set at\n.set reorder\n");
