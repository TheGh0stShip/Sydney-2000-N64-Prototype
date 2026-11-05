/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800D6F80\n.ent func_800D6F80\n"
    "func_800D6F80:\n"
    "lui $2,0x8007\n"
    "lw $7,29532($2)\n"
    "li $6,12\n"
    "sw $0,16($29)\n"
    "jal func_800AB2A4\n"
    "sw $0,20($29)\n"
    "lw $31,32($29)\n"
    "lw $17,28($29)\n"
    "lw $16,24($29)\n"
    "jr $31\n"
    "addiu $29,$29,40\n"
    ".end func_800D6F80\n.set at\n.set reorder\n");
