/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076964\n.ent func_80076964\n"
    "func_80076964:\n"
    "sb $2,2841($21)\n"
    "lbu $2,2841($21)\n"
    "andi $5,$19,0xff\n"
    "sltu $2,$5,$2\n"
    ".word 0x10400056\n"
    "lui $16,0x800f\n"
    "lw $6,-15760($22)\n"
    "lbu $3,2820($21)\n"
    "lbu $2,2573($6)\n"
    "mult $3,$2\n"
    "mflo $12\n"
    "addu $3,$12,$5\n"
    ".end func_80076964\n.set at\n.set reorder\n");
