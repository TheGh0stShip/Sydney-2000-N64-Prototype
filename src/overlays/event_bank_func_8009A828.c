/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8009A828\n.ent func_8009A828\n"
    "func_8009A828:\n"
    "li $7,7680\n"
    "lw $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_8009A828\n.set at\n.set reorder\n");
