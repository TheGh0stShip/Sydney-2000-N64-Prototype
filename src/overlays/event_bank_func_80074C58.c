/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80074C58\n.ent func_80074C58\n"
    "func_80074C58:\n"
    "lui $3,0x800f\n"
    "lw $2,10112($3)\n"
    "addiu $2,$2,-256\n"
    ".word 0x1C400006\n"
    ".end func_80074C58\n.set at\n.set reorder\n");
