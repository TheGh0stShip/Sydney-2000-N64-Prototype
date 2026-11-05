/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800A62EC\n.ent func_800A62EC\n"
    "func_800A62EC:\n"
    "addiu $29,$29,-24\n"
    "sw $31,16($29)\n"
    "jal func_8000F488\n"
    "nop\n"
    "lw $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_800A62EC\n.set at\n.set reorder\n");
