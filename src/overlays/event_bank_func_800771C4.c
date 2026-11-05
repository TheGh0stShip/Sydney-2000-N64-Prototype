/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800771C4\n.ent func_800771C4\n"
    "func_800771C4:\n"
    "addiu $29,$29,-72\n"
    "sw $21,60($29)\n"
    "move $21,$4\n"
    "lui $4,0x8010\n"
    ".end func_800771C4\n.set at\n.set reorder\n");
