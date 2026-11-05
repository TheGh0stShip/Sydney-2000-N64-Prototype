/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80074920\n.ent func_80074920\n"
    "func_80074920:\n"
    "lwc1 $f0,3372($16)\n"
    "lwc1 $f2,3376($16)\n"
    "swc1 $f0,3380($16)\n"
    ".end func_80074920\n.set at\n.set reorder\n");
