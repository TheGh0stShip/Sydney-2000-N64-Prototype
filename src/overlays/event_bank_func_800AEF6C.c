/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800AEF6C\n.ent func_800AEF6C\n"
    "func_800AEF6C:\n"
    "bltz $7,L_800AEF98\n"
    "lui $2,0x8010\n"
    "lw $2,-15760($2)\n"
    "lw $2,2564($2)\n"
    "beqz $2,L_800AEF98\n"
    "lui $4,0x800f\n"
    "addiu $4,$4,15296\n"
    "move $5,$7\n"
    "move $6,$0\n"
    "jal func_800C0110\n"
    "move $7,$6\n"
    "L_800AEF98:\n"
    "li $2,0x8000\n"
    "addu $2,$16,$2\n"
    ".end func_800AEF6C\n.set at\n.set reorder\n");
