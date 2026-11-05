/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007702C\n.ent func_8007702C\n"
    "func_8007702C:\n"
    "addu $3,$18,$7\n"
    "lui $5,0x1\n"
    "addu $3,$3,$5\n"
    "andi $6,$19,0xff\n"
    "addu $2,$18,$6\n"
    "addu $4,$2,$5\n"
    "lbu $2,3364($3)\n"
    "lbu $3,3364($4)\n"
    ".end func_8007702C\n.set at\n.set reorder\n");
