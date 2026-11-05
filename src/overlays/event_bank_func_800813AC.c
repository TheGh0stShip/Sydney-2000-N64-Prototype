/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800813AC\n.ent func_800813AC\n"
    "func_800813AC:\n"
    "lw $31,32($29)\n"
    "lw $19,28($29)\n"
    "lw $18,24($29)\n"
    "lw $17,20($29)\n"
    "lw $16,16($29)\n"
    "ldc1 $f22,48($29)\n"
    "ldc1 $f20,40($29)\n"
    "jr $31\n"
    "addiu $29,$29,56\n"
    ".end func_800813AC\n.set at\n.set reorder\n");
