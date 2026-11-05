/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8011D704\n.ent func_8011D704\n"
    "func_8011D704:\n"
    "addiu $29,$29,-32\n"
    "li $2,1\n"
    "move $5,$0\n"
    "lui $7,0x3f80\n"
    "li $6,-1\n"
    "sw $31,24($29)\n"
    "sw $2,172($4)\n"
    "sw $2,436($4)\n"
    "jal func_800B9E9C\n"
    "sw $0,16($29)\n"
    "lw $31,24($29)\n"
    "jr $31\n"
    "addiu $29,$29,32\n"
    ".end func_8011D704\n.set at\n.set reorder\n");
