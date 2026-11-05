/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8008115C\n.ent func_8008115C\n"
    "func_8008115C:\n"
    "li $6,15360\n"
    "jal func_800C0110\n"
    "li $7,30720\n"
    "lw $31,24($29)\n"
    "lw $17,20($29)\n"
    "lw $16,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,32\n"
    ".end func_8008115C\n.set at\n.set reorder\n");
