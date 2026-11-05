/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8009DA80\n.ent func_8009DA80\n"
    "func_8009DA80:\n"
    "li $5,215\n"
    "move $4,$18\n"
    "move $6,$0\n"
    "jal func_80074D14\n"
    "move $7,$6\n"
    "lui $2,0x1\n"
    "ori $2,$2,0xc200\n"
    "j func_800721CC\n"
    "sw $2,24144($18)\n"
    ".end func_8009DA80\n.set at\n.set reorder\n");
