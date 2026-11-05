/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80073110\n.ent func_80073110\n"
    "func_80073110:\n"
    "move $4,$20\n"
    "lwc1 $f0,16($29)\n"
    "lwc1 $f2,4($19)\n"
    ".end func_80073110\n.set at\n.set reorder\n");
