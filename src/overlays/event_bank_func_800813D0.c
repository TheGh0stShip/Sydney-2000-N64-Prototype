/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800813D0\n.ent func_800813D0\n"
    "func_800813D0:\n"
    "addiu $29,$29,-32\n"
    "sw $17,20($29)\n"
    "move $17,$4\n"
    "sw $16,16($29)\n"
    "addiu $16,$17,21396\n"
    "sw $31,24($29)\n"
    "lw $2,180($16)\n"
    "lh $4,24($2)\n"
    "lw $2,28($2)\n"
    "jalr $2\n"
    "addu $4,$16,$4\n"
    ".end func_800813D0\n.set at\n.set reorder\n");
