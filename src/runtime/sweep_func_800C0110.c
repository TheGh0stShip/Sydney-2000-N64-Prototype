/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800C0110\n.ent func_800C0110\n"
    "func_800C0110:\n"
    "addiu $29,$29,-32\n"
    "move $2,$6\n"
    "lui $6,0x800f\n"
    "addiu $6,$6,16452\n"
    "sw $7,16($29)\n"
    "sw $31,24($29)\n"
    "jal func_800BFFDC\n"
    "move $7,$2\n"
    "lw $31,24($29)\n"
    "jr $31\n"
    "addiu $29,$29,32\n"
    ".end func_800C0110\n.set at\n.set reorder\n");
