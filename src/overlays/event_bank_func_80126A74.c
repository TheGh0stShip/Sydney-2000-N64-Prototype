/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80126A74\n.ent func_80126A74\n"
    "func_80126A74:\n"
    "addiu $29,$29,-24\n"
    "sw $31,16($29)\n"
    "lw $2,4($4)\n"
    "lw $5,740($4)\n"
    "addiu $4,$4,2076\n"
    "lbu $6,1556($2)\n"
    "sltiu $5,$5,1\n"
    "xori $6,$6,0x5\n"
    "jal func_8009D8F8\n"
    "sltu $6,$0,$6\n"
    "lw $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_80126A74\n.set at\n.set reorder\n");
