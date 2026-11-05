/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007B25C\n.ent func_8007B25C\n"
    "func_8007B25C:\n"
    "move $6,$0\n"
    "jal func_80077EEC\n"
    "move $7,$6\n"
    "li $2,0x8000\n"
    ".end func_8007B25C\n.set at\n.set reorder\n");
