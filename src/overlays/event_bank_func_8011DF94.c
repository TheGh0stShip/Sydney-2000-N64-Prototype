/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8011DF94\n.ent func_8011DF94\n"
    "func_8011DF94:\n"
    "addiu $29,$29,-24\n"
    "sw $31,16($29)\n"
    "sw $0,236($4)\n"
    "sw $0,240($4)\n"
    "sw $0,244($4)\n"
    "sw $0,248($4)\n"
    "sw $0,252($4)\n"
    "sh $0,256($4)\n"
    "jal func_8008115C\n"
    "sw $0,172($4)\n"
    "lw $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_8011DF94\n.set at\n.set reorder\n");
