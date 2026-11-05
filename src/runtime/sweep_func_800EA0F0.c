/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800EA0F0\n.ent func_800EA0F0\n"
    "func_800EA0F0:\n"
    "addiu $29,$29,-24\n"
    "lui $4,0x8010\n"
    "addiu $4,$4,-720\n"
    "sw $31,16($29)\n"
    "jal func_800AC3A4\n"
    "li $5,2\n"
    "lw $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_800EA0F0\n.set at\n.set reorder\n");
