/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007754C\n.ent func_8007754C\n"
    "func_8007754C:\n"
    "li $2,2\n"
    "andi $7,$7,0xff\n"
    ".word 0x10E20005\n"
    "li $2,4\n"
    ".end func_8007754C\n.set at\n.set reorder\n");
