/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800AEAE8\n.ent func_800AEAE8\n"
    "func_800AEAE8:\n"
    "li $2,5\n"
    "lw $2,2564($4)\n"
    ".word 0x10400038\n"
    "lui $4,0x800f\n"
    "addiu $4,$4,15296\n"
    "j func_80076EB8\n"
    "li $5,297\n"
    ".end func_800AEAE8\n.set at\n.set reorder\n");
