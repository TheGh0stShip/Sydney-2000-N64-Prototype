/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800AB7DC\n.ent func_800AB7DC\n"
    "func_800AB7DC:\n"
    "addiu $29,$29,-24\n"
    "andi $5,$5,0x1\n"
    "beqz $5,L_800AB7F4\n"
    "sw $31,16($29)\n"
    "jal func_80004380\n"
    "nop\n"
    "L_800AB7F4:\n"
    "lw $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_800AB7DC\n.set at\n.set reorder\n");
