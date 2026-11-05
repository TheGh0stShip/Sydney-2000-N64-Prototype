/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076EB8\n.ent func_80076EB8\n"
    "func_80076EB8:\n"
    "li $13,5\n"
    ".word 0x146D0010\n"
    "andi $8,$19,0xff\n"
    "lui $2,0x8010\n"
    ".end func_80076EB8\n.set at\n.set reorder\n");
