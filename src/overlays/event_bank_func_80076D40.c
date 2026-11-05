/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076D40\n.ent func_80076D40\n"
    "func_80076D40:\n"
    "sw $0,16($29)\n"
    "sw $0,20($29)\n"
    "mflo $8\n"
    ".end func_80076D40\n.set at\n.set reorder\n");
