/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007D910\n.ent func_8007D910\n"
    "func_8007D910:\n"
    "move $3,$0\n"
    "move $4,$16\n"
    "L_8007D918:\n"
    "sw $0,216($4)\n"
    "addiu $3,$3,1\n"
    "sltiu $2,$3,4\n"
    "bnez $2,L_8007D918\n"
    "addiu $4,$4,4\n"
    "li $18,30\n"
    "li $2,15\n"
    "addiu $17,$16,352\n"
    "sh $2,380($16)\n"
    ".end func_8007D910\n.set at\n.set reorder\n");
