/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80075894\n.ent func_80075894\n"
    "func_80075894:\n"
    "beql $3,$0,L_8007589C\n"
    "li $3,1\n"
    "L_8007589C:\n"
    "lui $2,0x800f\n"
    "sw $3,5104($2)\n"
    "li $2,5\n"
    "sw $0,1216($18)\n"
    "sw $2,1552($18)\n"
    "lw $31,36($29)\n"
    "lw $18,32($29)\n"
    "lw $17,28($29)\n"
    "lw $16,24($29)\n"
    "jr $31\n"
    "addiu $29,$29,40\n"
    ".end func_80075894\n.set at\n.set reorder\n");
