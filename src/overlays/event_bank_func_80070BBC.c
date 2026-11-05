/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80070BBC\n.ent func_80070BBC\n"
    "func_80070BBC:\n"
    "lw $8,52($29)\n"
    "lw $3,12($8)\n"
    ".end func_80070BBC\n.set at\n.set reorder\n");
