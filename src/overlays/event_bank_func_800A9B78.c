/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800A9B78\n.ent func_800A9B78\n"
    "func_800A9B78:\n"
    "addiu $4,$4,17904\n"
    "jal func_8007735C\n"
    "move $4,$16\n"
    "j func_800721C0\n"
    "nop\n"
    ".end func_800A9B78\n.set at\n.set reorder\n");
