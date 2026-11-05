/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800761C0\n.ent func_800761C0\n"
    "func_800761C0:\n"
    "sw $0,172($4)\n"
    "sw $19,1552($4)\n"
    "jal func_80075F20\n"
    ".end func_800761C0\n.set at\n.set reorder\n");
