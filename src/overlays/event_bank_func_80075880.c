/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80075880\n.ent func_80075880\n"
    "func_80075880:\n"
    "sb $0,1213($18)\n"
    "sb $0,3364($2)\n"
    "jal func_800AC25C\n"
    "sb $0,3365($2)\n"
    "lw $3,1560($18)\n"
    ".end func_80075880\n.set at\n.set reorder\n");
