/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800C80FC\n.ent func_800C80FC\n"
    "func_800C80FC:\n"
    "addiu $29,$29,-24\n"
    "lui $2,0x8009\n"
    "addiu $2,$2,-30448\n"
    "sw $31,16($29)\n"
    "jal func_800ADE84\n"
    "sw $2,180($4)\n"
    "lw $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_800C80FC\n.set at\n.set reorder\n");
