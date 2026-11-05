/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80070A20\n.ent func_80070A20\n"
    "func_80070A20:\n"
    "lw $17,28($29)\n"
    "lw $16,24($29)\n"
    "jr $31\n"
    "addiu $29,$29,40\n"
    ".end func_80070A20\n.set at\n.set reorder\n");
