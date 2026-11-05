/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800767B4\n.ent func_800767B4\n"
    "func_800767B4:\n"
    "sw $2,17904($4)\n"
    "jal func_80008534\n"
    "move $4,$16\n"
    "j func_80073474\n"
    "sw $0,8($16)\n"
    ".end func_800767B4\n.set at\n.set reorder\n");
