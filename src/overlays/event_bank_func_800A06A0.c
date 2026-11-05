/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800A06A0\n.ent func_800A06A0\n"
    "func_800A06A0:\n"
    "addiu $2,$2,22684\n"
    "li $3,691\n"
    "sw $3,16($2)\n"
    "li $3,6144\n"
    "j func_80074908\n"
    "sw $3,32($2)\n"
    ".end func_800A06A0\n.set at\n.set reorder\n");
