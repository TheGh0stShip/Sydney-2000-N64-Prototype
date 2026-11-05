/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007ACE8\n.ent func_8007ACE8\n"
    "func_8007ACE8:\n"
    "addiu $29,$29,-72\n"
    "sw $19,52($29)\n"
    "move $19,$4\n"
    "sw $21,60($29)\n"
    "move $21,$5\n"
    ".end func_8007ACE8\n.set at\n.set reorder\n");
