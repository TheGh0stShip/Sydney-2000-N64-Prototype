/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007AE44\n.ent func_8007AE44\n"
    "func_8007AE44:\n"
    "sw $0,16($29)\n"
    "jal func_800AB2A4\n"
    "sw $0,20($29)\n"
    "j func_800722EC\n"
    "nop\n"
    ".end func_8007AE44\n.set at\n.set reorder\n");
