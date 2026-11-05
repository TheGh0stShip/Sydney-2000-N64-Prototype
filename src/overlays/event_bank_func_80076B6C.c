/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076B6C\n.ent func_80076B6C\n"
    "func_80076B6C:\n"
    "addu $2,$18,$2\n"
    "sw $0,22864($2)\n"
    ".end func_80076B6C\n.set at\n.set reorder\n");
