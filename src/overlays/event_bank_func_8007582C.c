/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007582C\n.ent func_8007582C\n"
    "func_8007582C:\n"
    "lh $4,16($2)\n"
    "lw $2,20($2)\n"
    "jalr $2\n"
    ".end func_8007582C\n.set at\n.set reorder\n");
