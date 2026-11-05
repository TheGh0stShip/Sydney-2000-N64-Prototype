/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80072B58\n.ent func_80072B58\n"
    "func_80072B58:\n"
    "sll $2,$2,0x2\n"
    "addu $2,$2,$8\n"
    "lw $5,0($2)\n"
    "j func_800731F8\n"
    "li $6,-1\n"
    ".end func_80072B58\n.set at\n.set reorder\n");
