/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80095824\n.ent func_80095824\n"
    "func_80095824:\n"
    "addiu $29,$29,-24\n"
    "sw $31,16($29)\n"
    "jal func_80097504\n"
    "addiu $4,$4,24188\n"
    "lw $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_80095824\n.set at\n.set reorder\n");
