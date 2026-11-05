/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80071900\n.ent func_80071900\n"
    "func_80071900:\n"
    "move $4,$22\n"
    "jal func_800AD9E8\n"
    "swc1 $f0,72($2)\n"
    "lui $5,0xc54c\n"
    "ori $5,$5,0xcb32\n"
    ".end func_80071900\n.set at\n.set reorder\n");
