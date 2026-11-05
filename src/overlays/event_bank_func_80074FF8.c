/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80074FF8\n.ent func_80074FF8\n"
    "func_80074FF8:\n"
    "move $4,$16\n"
    "jal func_800D29E0\n"
    "move $4,$16\n"
    "lui $4,0x1\n"
    "ori $4,$4,0x3c8\n"
    "addu $4,$18,$4\n"
    "lui $5,0x8007\n"
    "addiu $5,$5,25976\n"
    "li $6,1\n"
    "jal func_800D33A0\n"
    "li $7,-1\n"
    "move $4,$18\n"
    "li $5,37\n"
    "move $6,$0\n"
    ".end func_80074FF8\n.set at\n.set reorder\n");
