/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80074914\n.ent func_80074914\n"
    "func_80074914:\n"
    "swc1 $f20,2828($16)\n"
    "lwc1 $f0,3368($16)\n"
    "swc1 $f0,3376($16)\n"
    ".end func_80074914\n.set at\n.set reorder\n");
