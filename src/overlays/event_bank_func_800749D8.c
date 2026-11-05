/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800749D8\n.ent func_800749D8\n"
    "func_800749D8:\n"
    "sw $0,2844($3)\n"
    "jal func_80075E54\n"
    "move $4,$18\n"
    ".word 0x10400016\n"
    "lui $4,0x800f\n"
    "jal func_80076224\n"
    "move $4,$18\n"
    ".end func_800749D8\n.set at\n.set reorder\n");
