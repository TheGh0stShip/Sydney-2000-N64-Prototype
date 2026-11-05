/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007B93C\n.ent func_8007B93C\n"
    "func_8007B93C:\n"
    "li $5,12\n"
    "addu $4,$19,$4\n"
    "li $5,2\n"
    "jal func_800A9BE8\n"
    "nop\n"
    "jal func_80077FC4\n"
    "move $4,$19\n"
    "j func_80072930\n"
    "nop\n"
    ".end func_8007B93C\n.set at\n.set reorder\n");
