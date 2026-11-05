/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076C64\n.ent func_80076C64\n"
    "func_80076C64:\n"
    "beql $2,$0,L_80076C78\n"
    "lui $4,0x1\n"
    "jal func_8008382C\n"
    "nop\n"
    "lui $4,0x1\n"
    "L_80076C78:\n"
    ".end func_80076C64\n.set at\n.set reorder\n");
