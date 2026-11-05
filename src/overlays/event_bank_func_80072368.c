/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80072368\n.ent func_80072368\n"
    "func_80072368:\n"
    "lw $31,32($29)\n"
    "lw $19,28($29)\n"
    ".end func_80072368\n.set at\n.set reorder\n");
