/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8009D334\n.ent func_8009D334\n"
    "func_8009D334:\n"
    "addiu $29,$29,-24\n"
    "lui $6,0x75\n"
    "ori $6,$6,0x3000\n"
    "addiu $4,$4,15208\n"
    "move $5,$0\n"
    "sw $31,16($29)\n"
    "jal func_800CC294\n"
    "li $7,1\n"
    "lw $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_8009D334\n.set at\n.set reorder\n");
