/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80127004\n.ent func_80127004\n"
    "func_80127004:\n"
    "addiu $29,$29,-24\n"
    "move $6,$5\n"
    "sw $31,16($29)\n"
    "jal func_800AAB54\n"
    "li $5,16\n"
    "lw $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_80127004\n.set at\n.set reorder\n");
