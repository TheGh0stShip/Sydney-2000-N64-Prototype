/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80074D64\n.ent func_80074D64\n"
    "func_80074D64:\n"
    "lui $2,0x1\n"
    "addu $2,$18,$2\n"
    "sw $0,2832($2)\n"
    "sw $3,1216($18)\n"
    "li $2,2\n"
    ".end func_80074D64\n.set at\n.set reorder\n");
