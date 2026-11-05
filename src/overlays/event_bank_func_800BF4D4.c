/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800BF4D4\n.ent func_800BF4D4\n"
    "func_800BF4D4:\n"
    "lw $19,76($29)\n"
    "lw $18,72($29)\n"
    "lw $17,68($29)\n"
    "lw $16,64($29)\n"
    "ldc1 $f28,136($29)\n"
    "ldc1 $f26,128($29)\n"
    "ldc1 $f24,120($29)\n"
    "ldc1 $f22,112($29)\n"
    "ldc1 $f20,104($29)\n"
    "jr $31\n"
    "addiu $29,$29,144\n"
    ".end func_800BF4D4\n.set at\n.set reorder\n");
