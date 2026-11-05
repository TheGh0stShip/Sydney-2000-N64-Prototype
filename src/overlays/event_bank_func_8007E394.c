/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007E394\n.ent func_8007E394\n"
    "func_8007E394:\n"
    "lbu $3,3229($16)\n"
    "li $2,2\n"
    "beql $3,$2,L_8007E3A4\n"
    "li $4,3\n"
    "L_8007E3A4:\n"
    "lw $2,21356($19)\n"
    "andi $5,$20,0xff\n"
    "sb $4,426($2)\n"
    ".end func_8007E394\n.set at\n.set reorder\n");
