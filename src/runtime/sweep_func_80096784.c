/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80096784\n.ent func_80096784\n"
    "func_80096784:\n"
    "sb $0,0($4)\n"
    "sb $0,1($4)\n"
    "sb $0,2($4)\n"
    "sb $0,3($4)\n"
    "sb $0,4($4)\n"
    "sb $0,5($4)\n"
    "sb $0,6($4)\n"
    "jr $31\n"
    "sb $0,7($4)\n"
    ".end func_80096784\n.set at\n.set reorder\n");
