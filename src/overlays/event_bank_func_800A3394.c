/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800A3394\n.ent func_800A3394\n"
    "func_800A3394:\n"
    "li $5,1\n"
    "jal func_800717A0\n"
    "move $4,$18\n"
    "jal func_800B4794\n"
    "move $4,$0\n"
    "j func_80072914\n"
    "nop\n"
    ".end func_800A3394\n.set at\n.set reorder\n");
