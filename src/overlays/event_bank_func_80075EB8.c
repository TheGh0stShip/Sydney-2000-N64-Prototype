/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80075EB8\n.ent func_80075EB8\n"
    "func_80075EB8:\n"
    "move $3,$0\n"
    "move $4,$16\n"
    "L_80075EC0:\n"
    "sw $0,184($4)\n"
    "addiu $3,$3,1\n"
    "sltiu $2,$3,8\n"
    "bnez $2,L_80075EC0\n"
    ".end func_80075EB8\n.set at\n.set reorder\n");
