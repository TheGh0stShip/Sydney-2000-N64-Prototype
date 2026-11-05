/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007B678\n.ent func_8007B678\n"
    "func_8007B678:\n"
    ".word 0x10620008\n"
    "li $5,235\n"
    "j func_80072424\n"
    "lui $16,0x800f\n"
    ".end func_8007B678\n.set at\n.set reorder\n");
