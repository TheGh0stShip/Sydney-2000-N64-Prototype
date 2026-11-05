/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800A6C40\n.ent func_800A6C40\n"
    "func_800A6C40:\n"
    "lui $4,0x800f\n"
    "addiu $4,$4,15296\n"
    "j func_80075DF8\n"
    "li $5,513\n"
    ".end func_800A6C40\n.set at\n.set reorder\n");
