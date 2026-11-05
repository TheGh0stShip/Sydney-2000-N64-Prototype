/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8009D360\n.ent func_8009D360\n"
    "func_8009D360:\n"
    "move $4,$18\n"
    "jal func_80073438\n"
    "move $4,$18\n"
    "jal func_80072A5C\n"
    "move $4,$18\n"
    "j func_800716C8\n"
    "nop\n"
    ".end func_8009D360\n.set at\n.set reorder\n");
