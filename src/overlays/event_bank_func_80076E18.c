/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076E18\n.ent func_80076E18\n"
    "func_80076E18:\n"
    "sw $0,20($29)\n"
    "jal func_80083218\n"
    "move $4,$16\n"
    ".end func_80076E18\n.set at\n.set reorder\n");
