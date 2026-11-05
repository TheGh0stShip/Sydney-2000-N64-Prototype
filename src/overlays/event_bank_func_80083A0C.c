/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80083A0C\n.ent func_80083A0C\n"
    "func_80083A0C:\n"
    "jal func_800A9BE8\n"
    "li $5,2\n"
    "li $2,3\n"
    "j func_80072698\n"
    "sw $0,21540($18)\n"
    ".end func_80083A0C\n.set at\n.set reorder\n");
