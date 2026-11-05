/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800EDC38\n.ent func_800EDC38\n"
    "func_800EDC38:\n"
    "lui $2,0x8010\n"
    "lui $3,0x8010\n"
    "lui $9,0x8010\n"
    "lui $7,0x8010\n"
    "lbu $4,-448($2)\n"
    "lbu $5,-447($3)\n"
    "lbu $2,-446($9)\n"
    "lbu $3,15744($7)\n"
    ".end func_800EDC38\n.set at\n.set reorder\n");
