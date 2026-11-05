/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800A3E30\n.ent func_800A3E30\n"
    "func_800A3E30:\n"
    "bc1t L_800A3E40\n"
    "li $5,473\n"
    "move $4,$19\n"
    "li $5,472\n"
    "L_800A3E40:\n"
    "move $6,$0\n"
    "jal func_80076C64\n"
    "move $7,$6\n"
    "j func_80072E64\n"
    "nop\n"
    ".end func_800A3E30\n.set at\n.set reorder\n");
