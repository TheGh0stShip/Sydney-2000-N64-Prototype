/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800768AC\n.ent func_800768AC\n"
    "func_800768AC:\n"
    "addu $16,$19,$16\n"
    "jal func_80082360\n"
    "move $4,$16\n"
    "jal func_8008382C\n"
    "move $4,$16\n"
    "addiu $4,$20,9952\n"
    "move $5,$16\n"
    ".end func_800768AC\n.set at\n.set reorder\n");
