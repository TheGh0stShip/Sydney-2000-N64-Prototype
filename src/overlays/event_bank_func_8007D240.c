/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007D240\n.ent func_8007D240\n"
    "func_8007D240:\n"
    "sh $3,196($20)\n"
    "lhu $3,22($2)\n"
    "lui $2,0xff00\n"
    "sw $2,208($20)\n"
    "swc1 $f0,200($20)\n"
    "swc1 $f2,204($20)\n"
    "sw $16,212($20)\n"
    "jal func_80017B50\n"
    "sh $3,198($20)\n"
    "move $4,$16\n"
    ".end func_8007D240\n.set at\n.set reorder\n");
