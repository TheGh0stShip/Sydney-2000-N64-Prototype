/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800BAC24\n.ent func_800BAC24\n"
    "func_800BAC24:\n"
    "lw $19,116($29)\n"
    "lw $18,112($29)\n"
    "lw $17,108($29)\n"
    "lw $16,104($29)\n"
    "jr $31\n"
    "addiu $29,$29,128\n"
    ".end func_800BAC24\n.set at\n.set reorder\n");
