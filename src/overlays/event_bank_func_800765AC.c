/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800765AC\n.ent func_800765AC\n"
    "func_800765AC:\n"
    "addu $4,$3,$2\n"
    "li $8,1\n"
    "lb $3,0($4)\n"
    ".word 0x1072000B\n"
    "sll $2,$3,0x4\n"
    "subu $2,$2,$3\n"
    "lw $3,-15760($16)\n"
    "sll $2,$2,0x2\n"
    "addu $3,$3,$2\n"
    "lbu $2,32($3)\n"
    ".end func_800765AC\n.set at\n.set reorder\n");
