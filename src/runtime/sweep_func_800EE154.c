/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800EE154\n.ent func_800EE154\n"
    "func_800EE154:\n"
    "lui $2,0x8010\n"
    "li $3,255\n"
    "sb $3,15744($2)\n"
    "lui $2,0x8010\n"
    "sb $3,15745($2)\n"
    "lui $2,0x8010\n"
    "jr $31\n"
    "sb $3,15746($2)\n"
    ".end func_800EE154\n.set at\n.set reorder\n");
