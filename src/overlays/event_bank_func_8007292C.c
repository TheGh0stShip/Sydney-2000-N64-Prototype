/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007292C\n.ent func_8007292C\n"
    "func_8007292C:\n"
    "subu $3,$3,$2\n"
    "and $3,$3,$5\n"
    "srl $2,$3,0xf\n"
    "mult $2,$30\n"
    ".end func_8007292C\n.set at\n.set reorder\n");
