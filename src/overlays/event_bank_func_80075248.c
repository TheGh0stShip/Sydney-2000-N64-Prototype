/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80075248\n.ent func_80075248\n"
    "func_80075248:\n"
    "addu $2,$18,$2\n"
    "jal func_800D29E0\n"
    "sw $0,2832($2)\n"
    ".end func_80075248\n.set at\n.set reorder\n");
