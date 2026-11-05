/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800D1574\n.ent func_800D1574\n"
    "func_800D1574:\n"
    "move $4,$19\n"
    "li $2,30720\n"
    "sw $2,3852($19)\n"
    "li $2,3\n"
    "sw $2,17124($19)\n"
    "j func_80071A60\n"
    "sw $0,3860($19)\n"
    ".end func_800D1574\n.set at\n.set reorder\n");
