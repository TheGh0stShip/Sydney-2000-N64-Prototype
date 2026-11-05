/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800C87C8\n.ent func_800C87C8\n"
    "func_800C87C8:\n"
    "addiu $29,$29,-24\n"
    "lui $2,0x8009\n"
    "addiu $2,$2,-29704\n"
    "sw $31,16($29)\n"
    "jal func_800BA1B4\n"
    "sw $2,180($4)\n"
    "lw $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_800C87C8\n.set at\n.set reorder\n");
