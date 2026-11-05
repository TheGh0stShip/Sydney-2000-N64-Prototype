/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800A6C64\n.ent func_800A6C64\n"
    "func_800A6C64:\n"
    "addiu $29,$29,-24\n"
    "sw $16,16($29)\n"
    "sw $31,20($29)\n"
    "jal func_800AC3D4\n"
    "move $16,$4\n"
    "lui $2,0x8008\n"
    "addiu $2,$2,22496\n"
    "sw $2,180($16)\n"
    "move $2,$16\n"
    "lw $31,20($29)\n"
    "lw $16,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_800A6C64\n.set at\n.set reorder\n");
