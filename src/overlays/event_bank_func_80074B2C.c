/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80074B2C\n.ent func_80074B2C\n"
    "func_80074B2C:\n"
    "jal func_800757A0\n"
    "move $4,$18\n"
    "j func_80071890\n"
    "nop\n"
    ".end func_80074B2C\n.set at\n.set reorder\n");
