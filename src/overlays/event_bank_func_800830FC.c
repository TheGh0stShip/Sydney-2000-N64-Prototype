/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800830FC\n.ent func_800830FC\n"
    "func_800830FC:\n"
    "addiu $29,$29,-32\n"
    "sw $17,20($29)\n"
    "move $17,$4\n"
    "addiu $4,$17,21668\n"
    "sw $31,28($29)\n"
    "sw $18,24($29)\n"
    "jal func_800EADB4\n"
    "sw $16,16($29)\n"
    "lw $2,21540($17)\n"
    ".end func_800830FC\n.set at\n.set reorder\n");
