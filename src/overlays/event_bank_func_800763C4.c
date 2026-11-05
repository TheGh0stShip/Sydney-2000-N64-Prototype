/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800763C4\n.ent func_800763C4\n"
    "func_800763C4:\n"
    "lw $4,216($18)\n"
    "jal func_80017B24\n"
    "nop\n"
    "jal func_800BAC24\n"
    ".end func_800763C4\n.set at\n.set reorder\n");
