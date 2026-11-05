/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007719C\n.ent func_8007719C\n"
    "func_8007719C:\n"
    "jal func_800741C8\n"
    "andi $7,$7,0xff\n"
    "lw $31,52($29)\n"
    "lw $20,48($29)\n"
    "lw $19,44($29)\n"
    "lw $18,40($29)\n"
    "lw $17,36($29)\n"
    "lw $16,32($29)\n"
    "jr $31\n"
    "addiu $29,$29,56\n"
    ".end func_8007719C\n.set at\n.set reorder\n");
