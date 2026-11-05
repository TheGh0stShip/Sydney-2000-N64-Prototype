/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007B184\n.ent func_8007B184\n"
    "func_8007B184:\n"
    "sw $0,16($29)\n"
    "sw $0,20($29)\n"
    "mflo $8\n"
    "jal func_8001D5D8\n"
    ".end func_8007B184\n.set at\n.set reorder\n");
