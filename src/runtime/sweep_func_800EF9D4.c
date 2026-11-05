/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800EF9D4\n.ent func_800EF9D4\n"
    "func_800EF9D4:\n"
    "addiu $29,$29,-24\n"
    "sw $31,16($29)\n"
    "jal func_800ADE84\n"
    "nop\n"
    "lw $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_800EF9D4\n.set at\n.set reorder\n");
