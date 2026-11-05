/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80077070\n.ent func_80077070\n"
    "func_80077070:\n"
    "addu $2,$18,$2\n"
    "addu $2,$2,$5\n"
    "lw $3,3268($2)\n"
    "slt $2,$12,$3\n"
    ".word 0x1040000A\n"
    "subu $5,$12,$3\n"
    ".end func_80077070\n.set at\n.set reorder\n");
