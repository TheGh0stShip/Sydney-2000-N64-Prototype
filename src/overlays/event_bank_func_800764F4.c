/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800764F4\n.ent func_800764F4\n"
    "func_800764F4:\n"
    "sw $20,40($29)\n"
    "sw $18,32($29)\n"
    "sw $17,28($29)\n"
    "jal func_800BC274\n"
    "sw $16,24($29)\n"
    "lui $16,0x8010\n"
    "lui $2,0x1\n"
    ".end func_800764F4\n.set at\n.set reorder\n");
