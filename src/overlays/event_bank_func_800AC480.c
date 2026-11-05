/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800AC480\n.ent func_800AC480\n"
    "func_800AC480:\n"
    "lw $18,32($29)\n"
    "lw $17,28($29)\n"
    "lw $16,24($29)\n"
    "ldc1 $f24,64($29)\n"
    "ldc1 $f22,56($29)\n"
    "ldc1 $f20,48($29)\n"
    "jr $31\n"
    "addiu $29,$29,72\n"
    ".end func_800AC480\n.set at\n.set reorder\n");
