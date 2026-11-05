/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007AE1C\n.ent func_8007AE1C\n"
    "func_8007AE1C:\n"
    "lui $5,0x8010\n"
    "sll $2,$3,0x1\n"
    "addu $2,$2,$3\n"
    "lw $3,-15760($5)\n"
    "sll $2,$2,0x2\n"
    "addu $3,$3,$2\n"
    ".end func_8007AE1C\n.set at\n.set reorder\n");
