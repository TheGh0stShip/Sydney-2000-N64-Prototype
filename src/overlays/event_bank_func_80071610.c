/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80071610\n.ent func_80071610\n"
    "func_80071610:\n"
    "move $6,$18\n"
    "move $7,$19\n"
    "jal func_800A851C\n"
    "swc1 $f0,540($17)\n"
    "j func_800719B8\n"
    "andi $20,$23,0xff\n"
    ".end func_80071610\n.set at\n.set reorder\n");
