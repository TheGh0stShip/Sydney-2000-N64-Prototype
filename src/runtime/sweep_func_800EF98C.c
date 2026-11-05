/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800EF98C\n.ent func_800EF98C\n"
    "func_800EF98C:\n"
    "addiu $29,$29,-24\n"
    "li $2,66\n"
    "sw $31,16($29)\n"
    "sw $0,240($4)\n"
    "sw $0,216($4)\n"
    "sw $0,196($4)\n"
    "jal func_800EF89C\n"
    "sw $2,0($4)\n"
    "lw $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_800EF98C\n.set at\n.set reorder\n");
