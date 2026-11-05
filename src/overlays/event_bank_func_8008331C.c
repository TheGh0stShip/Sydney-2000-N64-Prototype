/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8008331C\n.ent func_8008331C\n"
    "func_8008331C:\n"
    "addu $3,$3,$2\n"
    "lw $2,0($3)\n"
    "jr $2\n"
    "nop\n"
    ".end func_8008331C\n.set at\n.set reorder\n");
