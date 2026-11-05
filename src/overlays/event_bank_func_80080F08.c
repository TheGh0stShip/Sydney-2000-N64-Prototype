/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80080F08\n.ent func_80080F08\n"
    "func_80080F08:\n"
    "swc1 $f0,20($2)\n"
    "j func_80077C28\n"
    ".end func_80080F08\n.set at\n.set reorder\n");
