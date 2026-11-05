/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80073278\n.ent func_80073278\n"
    "func_80073278:\n"
    "addiu $29,$29,-24\n"
    "sltiu $2,$5,12\n"
    ".word 0x1040003E\n"
    "sw $31,16($29)\n"
    "lui $2,0x8007\n"
    "addiu $2,$2,3208\n"
    "sll $3,$5,0x2\n"
    "addu $3,$3,$2\n"
    "lw $2,0($3)\n"
    "jr $2\n"
    "nop\n"
    ".end func_80073278\n.set at\n.set reorder\n");
