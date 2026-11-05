/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800DE3FC\n.ent func_800DE3FC\n"
    "func_800DE3FC:\n"
    "addiu $29,$29,-24\n"
    "sw $31,16($29)\n"
    "lw $4,188($4)\n"
    "jal func_800E8EB4\n"
    "nop\n"
    "jal func_800C4008\n"
    "nop\n"
    "lw $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_800DE3FC\n.set at\n.set reorder\n");
