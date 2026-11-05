/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800B67DC\n.ent func_800B67DC\n"
    "func_800B67DC:\n"
    "addiu $29,$29,-24\n"
    "lui $2,0x8007\n"
    "addiu $2,$2,5480\n"
    "andi $5,$5,0x1\n"
    "sw $31,16($29)\n"
    "beqz $5,L_800B6800\n"
    "sw $2,24($4)\n"
    "jal func_80004380\n"
    "nop\n"
    "L_800B6800:\n"
    "lw $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_800B67DC\n.set at\n.set reorder\n");
