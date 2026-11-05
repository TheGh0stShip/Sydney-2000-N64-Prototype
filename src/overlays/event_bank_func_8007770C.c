/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007770C\n.ent func_8007770C\n"
    "func_8007770C:\n"
    "addiu $29,$29,-24\n"
    "sw $31,16($29)\n"
    "lbu $2,1556($4)\n"
    "sltiu $2,$2,2\n"
    ".word 0x104000B1\n"
    "lui $2,0x1\n"
    ".end func_8007770C\n.set at\n.set reorder\n");
