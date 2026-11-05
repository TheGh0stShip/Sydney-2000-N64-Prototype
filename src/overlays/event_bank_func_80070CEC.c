/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80070CEC\n.ent func_80070CEC\n"
    "func_80070CEC:\n"
    "lwc1 $f2,3076($1)\n"
    "j func_800716F0\n"
    "swc1 $f0,5024($21)\n"
    ".end func_80070CEC\n.set at\n.set reorder\n");
