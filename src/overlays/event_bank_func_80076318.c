/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076318\n.ent func_80076318\n"
    "func_80076318:\n"
    "lh $4,24($2)\n"
    "lw $2,28($2)\n"
    "jalr $2\n"
    "addu $4,$16,$4\n"
    "jal func_800CE594\n"
    "sb $0,176($16)\n"
    "jal func_80073498\n"
    ".end func_80076318\n.set at\n.set reorder\n");
