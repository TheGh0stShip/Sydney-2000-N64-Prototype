/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80074B14\n.ent func_80074B14\n"
    "func_80074B14:\n"
    "li $2,56\n"
    ".word 0x14620008\n"
    "li $2,55\n"
    "lui $2,0x1\n"
    "addu $2,$18,$2\n"
    "sb $0,2820($2)\n"
    ".end func_80074B14\n.set at\n.set reorder\n");
