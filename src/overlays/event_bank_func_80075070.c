/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80075070\n.ent func_80075070\n"
    "func_80075070:\n"
    "li $5,56\n"
    "li $6,15\n"
    "jal func_800AC25C\n"
    "move $7,$0\n"
    "lui $2,0x800f\n"
    "lw $2,10024($2)\n"
    "bnez $2,L_80075098\n"
    "lui $3,0x800f\n"
    "li $2,1\n"
    "sw $2,10020($3)\n"
    "L_80075098:\n"
    "lbu $3,1556($18)\n"
    "li $2,2\n"
    ".word 0x54620004\n"
    ".end func_80075070\n.set at\n.set reorder\n");
