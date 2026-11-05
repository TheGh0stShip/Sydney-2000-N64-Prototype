/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8009BAD8\n.ent func_8009BAD8\n"
    "func_8009BAD8:\n"
    "addiu $29,$29,-32\n"
    "sw $31,24($29)\n"
    "sw $17,20($29)\n"
    "sw $16,16($29)\n"
    "lw $3,2560($2)\n"
    "sltiu $2,$3,6\n"
    ".word 0x1040007A\n"
    "lui $2,0x8007\n"
    "addiu $2,$2,5384\n"
    "sll $3,$3,0x2\n"
    "addu $3,$3,$2\n"
    "lw $2,0($3)\n"
    "jr $2\n"
    "nop\n"
    ".end func_8009BAD8\n.set at\n.set reorder\n");
