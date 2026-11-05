/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076B28\n.ent func_80076B28\n"
    "func_80076B28:\n"
    "lw $16,24($29)\n"
    "jr $31\n"
    "addiu $29,$29,64\n"
    ".end func_80076B28\n.set at\n.set reorder\n");
