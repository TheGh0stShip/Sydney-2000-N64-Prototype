/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80074F88\n.ent func_80074F88\n"
    "func_80074F88:\n"
    "li $6,12\n"
    "jal func_800AC25C\n"
    "move $7,$0\n"
    "j func_80072550\n"
    "nop\n"
    ".end func_80074F88\n.set at\n.set reorder\n");
