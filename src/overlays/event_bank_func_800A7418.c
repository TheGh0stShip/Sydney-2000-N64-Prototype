/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800A7418\n.ent func_800A7418\n"
    "func_800A7418:\n"
    "sltiu $2,$2,2\n"
    ".word 0x14400038\n"
    "lui $4,0x800f\n"
    "addiu $4,$4,15296\n"
    "j func_800764F0\n"
    "li $5,527\n"
    ".end func_800A7418\n.set at\n.set reorder\n");
