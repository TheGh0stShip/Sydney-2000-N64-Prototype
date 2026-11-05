/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80119064\n.ent func_80119064\n"
    "func_80119064:\n"
    "addiu $29,$29,-24\n"
    "sw $16,16($29)\n"
    "sw $31,20($29)\n"
    "jal func_800A63F0\n"
    "move $16,$4\n"
    "lui $2,0x8008\n"
    "addiu $2,$2,-8128\n"
    "sw $2,180($16)\n"
    "move $2,$16\n"
    "lw $31,20($29)\n"
    "lw $16,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_80119064\n.set at\n.set reorder\n");
