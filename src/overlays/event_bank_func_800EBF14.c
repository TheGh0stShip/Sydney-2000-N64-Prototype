/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800EBF14\n.ent func_800EBF14\n"
    "func_800EBF14:\n"
    "sll $2,$2,0x2\n"
    "addu $2,$16,$2\n"
    "lbu $2,939($2)\n"
    "sb $2,1089($16)\n"
    "lw $31,28($29)\n"
    "lw $16,24($29)\n"
    "jr $31\n"
    "addiu $29,$29,32\n"
    ".end func_800EBF14\n.set at\n.set reorder\n");
