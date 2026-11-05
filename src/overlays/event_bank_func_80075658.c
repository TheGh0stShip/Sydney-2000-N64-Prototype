/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80075658\n.ent func_80075658\n"
    "func_80075658:\n"
    "move $4,$18\n"
    "jal func_80075F20\n"
    "sw $0,2844($16)\n"
    "j func_80072550\n"
    "nop\n"
    ".end func_80075658\n.set at\n.set reorder\n");
