/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80080FA8\n.ent func_80080FA8\n"
    "func_80080FA8:\n"
    "jr $31\n"
    "sw $0,4($2)\n"
    ".end func_80080FA8\n.set at\n.set reorder\n");
