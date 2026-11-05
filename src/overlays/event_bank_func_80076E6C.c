/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076E6C\n.ent func_80076E6C\n"
    "func_80076E6C:\n"
    "lw $17,28($29)\n"
    "lw $16,24($29)\n"
    "jr $31\n"
    "addiu $29,$29,48\n"
    ".end func_80076E6C\n.set at\n.set reorder\n");
