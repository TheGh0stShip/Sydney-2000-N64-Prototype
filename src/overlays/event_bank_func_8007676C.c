/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007676C\n.ent func_8007676C\n"
    "func_8007676C:\n"
    "li $2,5\n"
    ".word 0x14620005\n"
    "nop\n"
    "lbu $2,3410($4)\n"
    "andi $2,$2,0x4\n"
    ".end func_8007676C\n.set at\n.set reorder\n");
