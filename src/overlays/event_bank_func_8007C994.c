/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007C994\n.ent func_8007C994\n"
    "func_8007C994:\n"
    "sll $2,$2,0x2\n"
    "addu $3,$3,$2\n"
    "lw $5,2580($3)\n"
    "j func_80073764\n"
    "move $7,$0\n"
    ".end func_8007C994\n.set at\n.set reorder\n");
