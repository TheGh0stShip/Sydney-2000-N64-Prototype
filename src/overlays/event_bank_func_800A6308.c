/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800A6308\n.ent func_800A6308\n"
    "func_800A6308:\n"
    "li $3,3\n"
    "li $2,3\n"
    "bne $3,$2,L_800A6334\n"
    "li $2,-1\n"
    "li $18,114\n"
    "sll $2,$4,0x1\n"
    "addu $2,$2,$4\n"
    "sll $2,$2,0x2\n"
    "addu $2,$2,$17\n"
    "lbu $20,1($2)\n"
    "li $2,-1\n"
    "L_800A6334:\n"
    ".end func_800A6308\n.set at\n.set reorder\n");
