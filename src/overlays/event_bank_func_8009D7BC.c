/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8009D7BC\n.ent func_8009D7BC\n"
    "func_8009D7BC:\n"
    "li $6,1\n"
    "jal func_800D33A0\n"
    "li $7,-1\n"
    "lui $2,0x1\n"
    "ori $2,$2,0x6800\n"
    "sw $2,24072($18)\n"
    "li $2,7\n"
    "j func_800721CC\n"
    "sb $2,24039($18)\n"
    ".end func_8009D7BC\n.set at\n.set reorder\n");
