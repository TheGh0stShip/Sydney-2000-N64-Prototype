/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80077514\n.ent func_80077514\n"
    "func_80077514:\n"
    "jal func_800C0110\n"
    "move $7,$6\n"
    "lw $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_80077514\n.set at\n.set reorder\n");
