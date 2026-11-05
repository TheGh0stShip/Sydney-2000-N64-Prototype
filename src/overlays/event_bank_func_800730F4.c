/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800730F4\n.ent func_800730F4\n"
    "func_800730F4:\n"
    "addiu $16,$16,1724\n"
    "lw $2,1904($2)\n"
    "addu $16,$22,$16\n"
    "lh $4,40($2)\n"
    "lw $2,44($2)\n"
    "jalr $2\n"
    "addu $4,$16,$4\n"
    ".end func_800730F4\n.set at\n.set reorder\n");
