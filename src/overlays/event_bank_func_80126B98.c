/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80126B98\n.ent func_80126B98\n"
    "func_80126B98:\n"
    "addiu $29,$29,-24\n"
    "addiu $4,$4,1048\n"
    "sw $31,16($29)\n"
    "jal func_800A9BE8\n"
    "andi $5,$5,0xff\n"
    "lw $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_80126B98\n.set at\n.set reorder\n");
