/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800718E0\n.ent func_800718E0\n"
    "func_800718E0:\n"
    "add.s $f0,$f2,$f0\n"
    "swc1 $f0,2096($16)\n"
    "lwc1 $f0,2092($16)\n"
    "addiu $2,$16,1744\n"
    "swc1 $f0,64($2)\n"
    "lwc1 $f0,4($18)\n"
    "swc1 $f0,68($2)\n"
    "lwc1 $f0,8($18)\n"
    ".end func_800718E0\n.set at\n.set reorder\n");
