/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007B448\n.ent func_8007B448\n"
    "func_8007B448:\n"
    "lw $5,4($21)\n"
    "jal func_800AB2A4\n"
    "move $7,$19\n"
    "li $2,0x8000\n"
    "addu $2,$19,$2\n"
    "j func_8007226C\n"
    "sw $0,3220($2)\n"
    ".end func_8007B448\n.set at\n.set reorder\n");
