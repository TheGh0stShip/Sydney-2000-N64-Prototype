/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007173C\n.ent func_8007173C\n"
    "func_8007173C:\n"
    "addu $3,$3,$16\n"
    "sw $2,0($3)\n"
    "li $2,12\n"
    "beql $20,$2,L_80071750\n"
    "li $20,11\n"
    "L_80071750:\n"
    "lw $2,216($21)\n"
    ".word 0x10400015\n"
    "sll $16,$17,0x1\n"
    "addu $16,$16,$17\n"
    "sll $16,$16,0x3\n"
    ".end func_8007173C\n.set at\n.set reorder\n");
