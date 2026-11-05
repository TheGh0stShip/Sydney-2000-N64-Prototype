/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8011C590\n.ent func_8011C590\n"
    "func_8011C590:\n"
    "addiu $29,$29,-24\n"
    "sw $31,16($29)\n"
    "sw $0,260($4)\n"
    "lw $5,260($4)\n"
    "sw $0,172($4)\n"
    "sw $0,264($4)\n"
    "jal func_80080E20\n"
    "sw $0,268($4)\n"
    "lw $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_8011C590\n.set at\n.set reorder\n");
