/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800AA630\n.ent func_800AA630\n"
    "func_800AA630:\n"
    "addiu $29,$29,-48\n"
    "sw $17,28($29)\n"
    "move $17,$4\n"
    "sw $18,32($29)\n"
    "lui $18,0x800f\n"
    "sw $16,24($29)\n"
    "addiu $16,$18,10960\n"
    "move $4,$16\n"
    "sw $31,40($29)\n"
    "sw $19,36($29)\n"
    ".end func_800AA630\n.set at\n.set reorder\n");
