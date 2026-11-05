/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007243C\n.ent func_8007243C\n"
    "func_8007243C:\n"
    "add.s $f0,$f0,$f20\n"
    "j func_80072950\n"
    "swc1 $f0,3540($2)\n"
    ".end func_8007243C\n.set at\n.set reorder\n");
