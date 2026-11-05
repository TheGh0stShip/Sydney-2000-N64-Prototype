/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800A32B4\n.ent func_800A32B4\n"
    "func_800A32B4:\n"
    "addiu $29,$29,-48\n"
    "sw $18,32($29)\n"
    "move $18,$4\n"
    "sw $20,40($29)\n"
    "move $20,$5\n"
    "sw $31,44($29)\n"
    ".end func_800A32B4\n.set at\n.set reorder\n");
