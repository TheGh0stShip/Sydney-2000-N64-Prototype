/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80074C2C\n.ent func_80074C2C\n"
    "func_80074C2C:\n"
    "addiu $29,$29,-40\n"
    "sw $18,32($29)\n"
    "move $18,$4\n"
    "sw $31,36($29)\n"
    "sw $17,28($29)\n"
    ".word 0x10A0031B\n"
    "sw $16,24($29)\n"
    "lui $2,0x1\n"
    "addu $2,$18,$2\n"
    "lw $2,3400($2)\n"
    ".word 0x1040000A\n"
    ".end func_80074C2C\n.set at\n.set reorder\n");
