/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8008337C\n.ent func_8008337C\n"
    "func_8008337C:\n"
    "move $5,$2\n"
    "move $4,$16\n"
    "mflo $8\n"
    "jal func_8001D640\n"
    ".end func_8008337C\n.set at\n.set reorder\n");
