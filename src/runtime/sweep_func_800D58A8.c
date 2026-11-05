/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800D58A8\n.ent func_800D58A8\n"
    "func_800D58A8:\n"
    "addiu $29,$29,-24\n"
    "sw $16,16($29)\n"
    "addiu $16,$4,220\n"
    "move $4,$16\n"
    "sw $31,20($29)\n"
    "jal func_800AE420\n"
    "move $5,$0\n"
    "lui $1,0x8009\n"
    "lwc1 $f0,-24136($1)\n"
    "swc1 $f0,244($16)\n"
    "lw $31,20($29)\n"
    "lw $16,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_800D58A8\n.set at\n.set reorder\n");
