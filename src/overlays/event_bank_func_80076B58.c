/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076B58\n.ent func_80076B58\n"
    "func_80076B58:\n"
    ".word 0x1040000D\n"
    "lui $4,0x800f\n"
    "addiu $4,$4,9952\n"
    "li $6,7\n"
    "li $2,0x8000\n"
    ".end func_80076B58\n.set at\n.set reorder\n");
