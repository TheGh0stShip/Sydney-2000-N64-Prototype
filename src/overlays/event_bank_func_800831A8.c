/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800831A8\n.ent func_800831A8\n"
    "func_800831A8:\n"
    "sb $18,184($2)\n"
    "jal func_800A9BE8\n"
    "li $5,7\n"
    "addiu $2,$17,1360\n"
    "sb $16,185($2)\n"
    "j func_80071ED4\n"
    "sb $16,184($2)\n"
    ".end func_800831A8\n.set at\n.set reorder\n");
