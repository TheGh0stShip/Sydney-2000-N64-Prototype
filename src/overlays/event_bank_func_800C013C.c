/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800C013C\n.ent func_800C013C\n"
    "func_800C013C:\n"
    "addiu $29,$29,-32\n"
    "sw $16,16($29)\n"
    "sw $31,24($29)\n"
    "sw $17,20($29)\n"
    "lw $5,0($5)\n"
    "li $2,3\n"
    ".word 0x10A2006B\n"
    "move $16,$4\n"
    "li $2,5\n"
    ".word 0x14A20068\n"
    "nop\n"
    ".end func_800C013C\n.set at\n.set reorder\n");
