/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800BF36C\n.ent func_800BF36C\n"
    "func_800BF36C:\n"
    "addiu $29,$29,-24\n"
    "sw $31,16($29)\n"
    "sb $6,380($4)\n"
    "jal func_800BE630\n"
    "sw $5,376($4)\n"
    "lw $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_800BF36C\n.set at\n.set reorder\n");
