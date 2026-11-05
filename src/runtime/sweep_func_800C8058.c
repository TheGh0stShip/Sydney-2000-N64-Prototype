/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800C8058\n.ent func_800C8058\n"
    "func_800C8058:\n"
    "addiu $29,$29,-24\n"
    "sw $16,16($29)\n"
    "move $16,$4\n"
    "sw $31,20($29)\n"
    "lw $2,180($16)\n"
    "lh $4,24($2)\n"
    "lw $2,28($2)\n"
    "jalr $2\n"
    "addu $4,$16,$4\n"
    "sw $0,196($16)\n"
    "lw $31,20($29)\n"
    "lw $16,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_800C8058\n.set at\n.set reorder\n");
