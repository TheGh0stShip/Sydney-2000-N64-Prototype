/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80083188\n.ent func_80083188\n"
    "func_80083188:\n"
    "li $18,1\n"
    ".word 0x12120007\n"
    "addiu $4,$17,1116\n"
    "jal func_800A9BE8\n"
    "li $5,10\n"
    "addiu $2,$17,1360\n"
    "sb $18,185($2)\n"
    "j func_80071ED4\n"
    ".end func_80083188\n.set at\n.set reorder\n");
