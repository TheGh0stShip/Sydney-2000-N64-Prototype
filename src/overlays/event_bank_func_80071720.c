/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80071720\n.ent func_80071720\n"
    "func_80071720:\n"
    "lw $8,52($29)\n"
    "li $6,6\n"
    "addu $2,$8,$16\n"
    "lw $5,0($2)\n"
    "jal func_8007A760\n"
    "subu $6,$6,$17\n"
    "addiu $3,$29,32\n"
    ".end func_80071720\n.set at\n.set reorder\n");
