/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800832B8\n.ent func_800832B8\n"
    "func_800832B8:\n"
    "sb $2,1551($17)\n"
    "sw $3,1628($17)\n"
    "lw $31,28($29)\n"
    "lw $18,24($29)\n"
    "lw $17,20($29)\n"
    "lw $16,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,32\n"
    ".end func_800832B8\n.set at\n.set reorder\n");
