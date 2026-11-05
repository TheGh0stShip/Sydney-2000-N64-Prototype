/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8010B114\n.ent func_8010B114\n"
    "func_8010B114:\n"
    "addiu $29,$29,-24\n"
    "lui $2,0x8008\n"
    "addiu $2,$2,-29904\n"
    "sw $31,16($29)\n"
    "jal func_800BA1B4\n"
    "sw $2,180($4)\n"
    "lw $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_8010B114\n.set at\n.set reorder\n");
