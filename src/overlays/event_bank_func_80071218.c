/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80071218\n.ent func_80071218\n"
    "func_80071218:\n"
    "jal func_800AAA60\n"
    "addiu $6,$6,2504\n"
    "lw $2,184($21)\n"
    ".word 0x10400003\n"
    ".end func_80071218\n.set at\n.set reorder\n");
