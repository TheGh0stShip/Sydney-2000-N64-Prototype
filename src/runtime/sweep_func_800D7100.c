/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800D7100\n.ent func_800D7100\n"
    "func_800D7100:\n"
    "addiu $29,$29,-24\n"
    "lui $2,0x8008\n"
    "addiu $2,$2,26008\n"
    "sw $31,16($29)\n"
    "jal func_800ADDA4\n"
    "sw $2,180($4)\n"
    "lw $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_800D7100\n.set at\n.set reorder\n");
