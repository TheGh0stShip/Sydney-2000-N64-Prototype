/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800A73A4\n.ent func_800A73A4\n"
    "func_800A73A4:\n"
    "addiu $2,$2,-3\n"
    "sltiu $2,$2,2\n"
    ".word 0x14400054\n"
    "lui $4,0x800f\n"
    "addiu $4,$4,15296\n"
    "j func_800764F0\n"
    "li $5,529\n"
    ".end func_800A73A4\n.set at\n.set reorder\n");
