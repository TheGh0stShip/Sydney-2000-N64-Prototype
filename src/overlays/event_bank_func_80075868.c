/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80075868\n.ent func_80075868\n"
    "func_80075868:\n"
    "li $5,56\n"
    "li $6,18\n"
    "move $7,$0\n"
    "lui $2,0x1\n"
    "addu $2,$18,$2\n"
    "sb $0,2840($2)\n"
    ".end func_80075868\n.set at\n.set reorder\n");
