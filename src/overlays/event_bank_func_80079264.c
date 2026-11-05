/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80079264\n.ent func_80079264\n"
    "func_80079264:\n"
    "lw $2,28568($2)\n"
    "lwc1 $f0,2752($2)\n"
    "li $2,1\n"
    "jr $31\n"
    "swc1 $f0,0($6)\n"
    ".end func_80079264\n.set at\n.set reorder\n");
