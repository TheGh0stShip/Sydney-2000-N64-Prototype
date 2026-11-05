/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800837C0\n.ent func_800837C0\n"
    "func_800837C0:\n"
    "jal func_80076460\n"
    "move $4,$17\n"
    "lw $31,24($29)\n"
    "lw $17,20($29)\n"
    "lw $16,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,32\n"
    ".end func_800837C0\n.set at\n.set reorder\n");
