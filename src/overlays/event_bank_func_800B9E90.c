/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800B9E90\n.ent func_800B9E90\n"
    "func_800B9E90:\n"
    "jal func_8001D4B8\n"
    "li $7,1\n"
    "lw $4,104($16)\n"
    ".end func_800B9E90\n.set at\n.set reorder\n");
