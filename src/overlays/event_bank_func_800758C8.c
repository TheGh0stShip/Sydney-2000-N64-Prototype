/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800758C8\n.ent func_800758C8\n"
    "func_800758C8:\n"
    "addiu $29,$29,-72\n"
    "sw $20,40($29)\n"
    "move $20,$4\n"
    "sw $31,44($29)\n"
    "sw $19,36($29)\n"
    "sw $18,32($29)\n"
    "sw $17,28($29)\n"
    "sw $16,24($29)\n"
    "sdc1 $f24,64($29)\n"
    "sdc1 $f22,56($29)\n"
    ".end func_800758C8\n.set at\n.set reorder\n");
