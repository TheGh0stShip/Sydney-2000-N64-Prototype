/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80071600\n.ent func_80071600\n"
    "func_80071600:\n"
    "swc1 $f0,4860($16)\n"
    "lwc1 $f0,540($17)\n"
    "move $5,$20\n"
    ".end func_80071600\n.set at\n.set reorder\n");
