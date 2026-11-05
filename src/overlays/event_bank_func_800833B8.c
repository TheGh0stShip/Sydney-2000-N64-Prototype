/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800833B8\n.ent func_800833B8\n"
    "func_800833B8:\n"
    "jal func_800D33A0\n"
    "sw $3,30544($2)\n"
    "jal func_8007597C\n"
    "move $4,$17\n"
    "j func_8007211C\n"
    "li $2,28\n"
    ".end func_800833B8\n.set at\n.set reorder\n");
