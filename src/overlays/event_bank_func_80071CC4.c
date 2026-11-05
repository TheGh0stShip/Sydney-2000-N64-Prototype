/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80071CC4\n.ent func_80071CC4\n"
    "func_80071CC4:\n"
    "sw $2,228($21)\n"
    "lui $4,0x8007\n"
    "j func_800721F8\n"
    "addiu $4,$4,2840\n"
    ".end func_80071CC4\n.set at\n.set reorder\n");
