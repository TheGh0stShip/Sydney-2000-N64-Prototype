/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80081400\n.ent func_80081400\n"
    "func_80081400:\n"
    "jal func_800CFFC4\n"
    "sb $0,176($4)\n"
    "jal func_800CCB0C\n"
    "addiu $4,$17,31156\n"
    "jal func_800D29E0\n"
    "addiu $4,$17,13200\n"
    "lw $31,24($29)\n"
    "lw $17,20($29)\n"
    "lw $16,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,32\n"
    ".end func_80081400\n.set at\n.set reorder\n");
