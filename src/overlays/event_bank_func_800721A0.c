/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800721A0\n.ent func_800721A0\n"
    "func_800721A0:\n"
    "lw $2,28($2)\n"
    "jalr $2\n"
    "addu $4,$3,$4\n"
    "lw $3,184($19)\n"
    ".end func_800721A0\n.set at\n.set reorder\n");
