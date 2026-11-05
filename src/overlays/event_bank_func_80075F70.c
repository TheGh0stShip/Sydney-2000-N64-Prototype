/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80075F70\n.ent func_80075F70\n"
    "func_80075F70:\n"
    "lw $2,12($17)\n"
    "lhu $3,18($17)\n"
    "addiu $2,$2,4\n"
    "addiu $3,$3,1\n"
    "sw $2,12($17)\n"
    ".end func_80075F70\n.set at\n.set reorder\n");
