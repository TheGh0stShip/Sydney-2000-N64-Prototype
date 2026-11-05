/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80074D54\n.ent func_80074D54\n"
    "func_80074D54:\n"
    "jal func_80075F94\n"
    "move $7,$6\n"
    "lui $3,0x1\n"
    "ori $3,$3,0x2c00\n"
    ".end func_80074D54\n.set at\n.set reorder\n");
