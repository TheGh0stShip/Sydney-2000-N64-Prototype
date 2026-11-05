/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007AA40\n.ent func_8007AA40\n"
    "func_8007AA40:\n"
    "li $20,0x8cdc\n"
    "li $2,0x8a20\n"
    "addu $2,$19,$2\n"
    "sb $0,3231($16)\n"
    "sw $0,376($2)\n"
    "andi $3,$18,0xff\n"
    ".end func_8007AA40\n.set at\n.set reorder\n");
