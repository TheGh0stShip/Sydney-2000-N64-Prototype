/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800716F0\n.ent func_800716F0\n"
    "func_800716F0:\n"
    "sw $8,64($29)\n"
    "sw $2,22196($3)\n"
    "andi $17,$23,0xff\n"
    "sltiu $2,$17,3\n"
    ".word 0x1040015B\n"
    "li $2,11\n"
    "lw $8,52($29)\n"
    "lw $20,12($8)\n"
    "beql $20,$2,L_80071718\n"
    "li $20,12\n"
    "L_80071718:\n"
    "move $4,$20\n"
    "sll $16,$17,0x2\n"
    ".end func_800716F0\n.set at\n.set reorder\n");
