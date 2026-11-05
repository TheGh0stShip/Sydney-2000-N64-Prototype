/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800AAC84\n.ent func_800AAC84\n"
    "func_800AAC84:\n"
    "addiu $29,$29,-24\n"
    "sw $31,16($29)\n"
    "lw $4,4($6)\n"
    "lw $5,4($5)\n"
    "jal func_800B3870\n"
    "move $6,$7\n"
    "lw $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_800AAC84\n.set at\n.set reorder\n");
