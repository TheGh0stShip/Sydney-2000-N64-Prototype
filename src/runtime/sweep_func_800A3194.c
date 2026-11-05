/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800A3194\n.ent func_800A3194\n"
    "func_800A3194:\n"
    "addiu $29,$29,-24\n"
    "sw $31,16($29)\n"
    "lw $2,40($4)\n"
    "beqz $2,L_800A31B0\n"
    "li $4,-1\n"
    "jal func_8001DA28\n"
    "move $5,$0\n"
    "L_800A31B0:\n"
    "lw $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_800A3194\n.set at\n.set reorder\n");
