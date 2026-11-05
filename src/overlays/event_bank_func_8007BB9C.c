/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007BB9C\n.ent func_8007BB9C\n"
    "func_8007BB9C:\n"
    "lui $2,0x800f\n"
    "lw $3,10012($2)\n"
    "li $2,7\n"
    ".word 0x14620005\n"
    "move $4,$19\n"
    ".end func_8007BB9C\n.set at\n.set reorder\n");
