/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007E080\n.ent func_8007E080\n"
    "func_8007E080:\n"
    "sll $2,$3,0x1\n"
    "addu $2,$2,$3\n"
    "sll $2,$2,0x2\n"
    "lw $3,-15760($4)\n"
    "addiu $2,$2,2576\n"
    "addu $2,$3,$2\n"
    ".end func_8007E080\n.set at\n.set reorder\n");
