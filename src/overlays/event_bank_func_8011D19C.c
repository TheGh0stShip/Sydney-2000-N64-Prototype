/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8011D19C\n.ent func_8011D19C\n"
    "func_8011D19C:\n"
    "addiu $29,$29,-24\n"
    "sw $31,16($29)\n"
    "jal func_800ADE84\n"
    "nop\n"
    "lw $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_8011D19C\n.set at\n.set reorder\n");
