/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80073318\n.ent func_80073318\n"
    "func_80073318:\n"
    "lui $4,0x800f\n"
    "addiu $4,$4,15296\n"
    "j func_80073854\n"
    "li $5,83\n"
    ".end func_80073318\n.set at\n.set reorder\n");
