/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007439C\n.ent func_8007439C\n"
    "func_8007439C:\n"
    "sll $2,$17,0x2\n"
    "addu $2,$18,$2\n"
    "lui $19,0x1\n"
    "addu $2,$2,$19\n"
    ".end func_8007439C\n.set at\n.set reorder\n");
