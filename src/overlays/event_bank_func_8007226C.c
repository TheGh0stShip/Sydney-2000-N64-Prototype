/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007226C\n.ent func_8007226C\n"
    "func_8007226C:\n"
    "lw $2,12($2)\n"
    "jalr $2\n"
    "addu $4,$3,$4\n"
    ".end func_8007226C\n.set at\n.set reorder\n");
