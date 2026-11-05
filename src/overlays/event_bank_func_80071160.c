/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80071160\n.ent func_80071160\n"
    "func_80071160:\n"
    "addu $4,$3,$4\n"
    "lui $1,0x8007\n"
    "lwc1 $f0,3128($1)\n"
    "lui $1,0x8007\n"
    "lwc1 $f2,3132($1)\n"
    "j func_800716F0\n"
    "swc1 $f0,5024($21)\n"
    ".end func_80071160\n.set at\n.set reorder\n");
