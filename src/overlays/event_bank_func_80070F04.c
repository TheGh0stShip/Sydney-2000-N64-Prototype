/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80070F04\n.ent func_80070F04\n"
    "func_80070F04:\n"
    "lwc1 $f0,3104($1)\n"
    "lui $1,0x8007\n"
    "lwc1 $f2,3108($1)\n"
    "j func_800716F0\n"
    "swc1 $f0,5024($21)\n"
    ".end func_80070F04\n.set at\n.set reorder\n");
