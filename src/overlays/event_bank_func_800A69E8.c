/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800A69E8\n.ent func_800A69E8\n"
    "func_800A69E8:\n"
    "sltiu $2,$2,2\n"
    ".word 0x14400105\n"
    "lui $4,0x800f\n"
    "addiu $4,$4,15296\n"
    "j func_80075DF8\n"
    "li $5,496\n"
    ".end func_800A69E8\n.set at\n.set reorder\n");
