/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80119040\n.ent func_80119040\n"
    "func_80119040:\n"
    "addiu $29,$29,-24\n"
    "lui $2,0x8008\n"
    "addiu $2,$2,-8128\n"
    "sw $31,16($29)\n"
    "jal func_800A63CC\n"
    "sw $2,180($4)\n"
    "lw $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_80119040\n.set at\n.set reorder\n");
