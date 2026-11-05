/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80080FDC\n.ent func_80080FDC\n"
    "func_80080FDC:\n"
    "addiu $29,$29,-24\n"
    "lui $4,0x800f\n"
    "sw $16,16($29)\n"
    "lui $16,0x8008\n"
    "addiu $4,$4,10072\n"
    "sw $31,20($29)\n"
    "jal func_800AA658\n"
    "addiu $5,$16,-30820\n"
    "lw $31,20($29)\n"
    "sw $0,-30820($16)\n"
    "lw $16,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_80080FDC\n.set at\n.set reorder\n");
