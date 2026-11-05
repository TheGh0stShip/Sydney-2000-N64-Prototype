/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007983C\n.ent func_8007983C\n"
    "func_8007983C:\n"
    "lw $18,24($29)\n"
    "lw $17,20($29)\n"
    "lw $16,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,40\n"
    ".end func_8007983C\n.set at\n.set reorder\n");
