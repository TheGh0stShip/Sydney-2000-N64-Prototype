/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007E45C\n.ent func_8007E45C\n"
    "func_8007E45C:\n"
    "addiu $29,$29,-48\n"
    "sw $18,32($29)\n"
    "move $18,$4\n"
    "li $4,0x8bc0\n"
    ".end func_8007E45C\n.set at\n.set reorder\n");
