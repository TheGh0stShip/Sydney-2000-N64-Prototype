/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8009D334\n.ent func_8009D334\n"
    "func_8009D334:\n"
    "jal func_800751F4\n"
    "sb $0,24037($18)\n"
    "jal func_8007511C\n"
    "move $4,$18\n"
    "j func_800716C8\n"
    "nop\n"
    ".end func_8009D334\n.set at\n.set reorder\n");
