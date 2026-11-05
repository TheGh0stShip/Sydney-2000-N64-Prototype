/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800AAA60\n.ent func_800AAA60\n"
    "func_800AAA60:\n"
    "andi $3,$4,0xff\n"
    "andi $3,$7,0xff\n"
    "addiu $7,$7,1\n"
    "lui $4,0x8010\n"
    ".end func_800AAA60\n.set at\n.set reorder\n");
