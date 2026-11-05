/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8009C100\n.ent func_8009C100\n"
    "func_8009C100:\n"
    "lw $16,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,40\n"
    ".end func_8009C100\n.set at\n.set reorder\n");
