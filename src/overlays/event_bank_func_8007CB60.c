/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007CB60\n.ent func_8007CB60\n"
    "func_8007CB60:\n"
    "li $2,14\n"
    "jal func_80077EEC\n"
    "sw $2,3220($16)\n"
    "j func_80073CC4\n"
    "nop\n"
    ".end func_8007CB60\n.set at\n.set reorder\n");
