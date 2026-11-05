/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80081030\n.ent func_80081030\n"
    "func_80081030:\n"
    "sw $16,152($29)\n"
    "jal func_800DA804\n"
    "sw $0,16($29)\n"
    "li $2,0x8000\n"
    ".end func_80081030\n.set at\n.set reorder\n");
