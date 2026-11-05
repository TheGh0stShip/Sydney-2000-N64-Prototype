/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800766E4\n.ent func_800766E4\n"
    "func_800766E4:\n"
    "lui $16,0x1\n"
    "lw $5,24($17)\n"
    "addu $16,$19,$16\n"
    "sw $2,16($29)\n"
    "sw $0,20($29)\n"
    "lw $7,3232($16)\n"
    "jal func_800AB2A4\n"
    "li $6,3\n"
    "lui $2,0x1\n"
    "ori $2,$2,0xcb4\n"
    "move $4,$18\n"
    ".end func_800766E4\n.set at\n.set reorder\n");
