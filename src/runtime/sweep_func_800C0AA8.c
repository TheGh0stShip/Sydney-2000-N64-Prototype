/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800C0AA8\n.ent func_800C0AA8\n"
    "func_800C0AA8:\n"
    "addiu $29,$29,-24\n"
    "sw $31,16($29)\n"
    "lw $3,172($4)\n"
    "li $2,2\n"
    "bne $3,$2,L_800C0AC8\n"
    "nop\n"
    "jal func_800C0A5C\n"
    "nop\n"
    "L_800C0AC8:\n"
    "lw $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_800C0AA8\n.set at\n.set reorder\n");
