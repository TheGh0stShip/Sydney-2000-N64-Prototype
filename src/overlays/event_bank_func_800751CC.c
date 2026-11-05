/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800751CC\n.ent func_800751CC\n"
    "func_800751CC:\n"
    "lui $5,0x8007\n"
    "addiu $5,$5,26056\n"
    "li $6,1\n"
    "li $7,-1\n"
    "lui $16,0x1\n"
    "addu $16,$18,$16\n"
    "move $17,$6\n"
    "jal func_800D33A0\n"
    "sw $17,2832($16)\n"
    "addiu $4,$18,1584\n"
    ".end func_800751CC\n.set at\n.set reorder\n");
