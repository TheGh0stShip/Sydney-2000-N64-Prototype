/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800A6C40\n.ent func_800A6C40\n"
    "func_800A6C40:\n"
    "addiu $29,$29,-24\n"
    "lui $2,0x8008\n"
    "addiu $2,$2,22496\n"
    "sw $31,16($29)\n"
    "jal func_800AC3A4\n"
    "sw $2,180($4)\n"
    "lw $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_800A6C40\n.set at\n.set reorder\n");
