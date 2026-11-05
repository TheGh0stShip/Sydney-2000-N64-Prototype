/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800836D8\n.ent func_800836D8\n"
    "func_800836D8:\n"
    "move $4,$16\n"
    "mflo $8\n"
    "jal func_8001D640\n"
    "sra $6,$8,0xf\n"
    "li $2,1\n"
    "sb $2,21618($17)\n"
    ".end func_800836D8\n.set at\n.set reorder\n");
