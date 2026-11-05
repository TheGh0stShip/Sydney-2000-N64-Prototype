/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076904\n.ent func_80076904\n"
    "func_80076904:\n"
    "lw $16,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,40\n"
    ".end func_80076904\n.set at\n.set reorder\n");
