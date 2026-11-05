/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007E240\n.ent func_8007E240\n"
    "func_8007E240:\n"
    "sw $0,32($2)\n"
    "sw $0,24($2)\n"
    "sw $0,16($2)\n"
    "sw $0,8($2)\n"
    "sw $0,4($2)\n"
    "sw $0,72($2)\n"
    "sw $0,68($2)\n"
    "sw $0,64($2)\n"
    "swc1 $f0,40($2)\n"
    ".end func_8007E240\n.set at\n.set reorder\n");
