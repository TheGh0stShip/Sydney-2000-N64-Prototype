/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80071EEC\n.ent func_80071EEC\n"
    "func_80071EEC:\n"
    "move $5,$0\n"
    "sw $2,5028($21)\n"
    "addiu $2,$21,4284\n"
    "sb $0,4457($21)\n"
    "sb $0,4460($21)\n"
    ".end func_80071EEC\n.set at\n.set reorder\n");
