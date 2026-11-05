/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800EBE2C\n.ent func_800EBE2C\n"
    "func_800EBE2C:\n"
    "addiu $29,$29,-40\n"
    "sw $6,20($29)\n"
    "lui $6,0x3f80\n"
    "sw $5,16($29)\n"
    "addiu $5,$29,16\n"
    "sw $31,32($29)\n"
    "jal func_800EBC08\n"
    "sw $7,24($29)\n"
    "lw $31,32($29)\n"
    "jr $31\n"
    "addiu $29,$29,40\n"
    ".end func_800EBE2C\n.set at\n.set reorder\n");
