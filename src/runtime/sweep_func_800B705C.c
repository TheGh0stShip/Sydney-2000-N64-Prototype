/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800B705C\n.ent func_800B705C\n"
    "func_800B705C:\n"
    "addiu $29,$29,-24\n"
    "lui $4,0x800f\n"
    "addiu $4,$4,22784\n"
    "li $5,15\n"
    "sw $31,16($29)\n"
    "jal func_800D56D0\n"
    "move $6,$0\n"
    "lw $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_800B705C\n.set at\n.set reorder\n");
