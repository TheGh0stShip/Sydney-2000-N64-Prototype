/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800A9AE4\n.ent func_800A9AE4\n"
    "func_800A9AE4:\n"
    "addiu $29,$29,-24\n"
    "move $2,$4\n"
    "sw $31,16($29)\n"
    "lw $3,192($2)\n"
    "lw $4,220($2)\n"
    "move $6,$5\n"
    "sw $6,192($2)\n"
    "sw $3,196($2)\n"
    "jal func_800B4ACC\n"
    "move $5,$3\n"
    "lw $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_800A9AE4\n.set at\n.set reorder\n");
