/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800760C0\n.ent func_800760C0\n"
    "func_800760C0:\n"
    "sw $4,4($2)\n"
    "addiu $4,$4,21600\n"
    "addiu $3,$3,1\n"
    "j func_80072D4C\n"
    "sh $5,0($2)\n"
    ".end func_800760C0\n.set at\n.set reorder\n");
