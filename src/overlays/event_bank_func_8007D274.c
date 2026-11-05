/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007D274\n.ent func_8007D274\n"
    "func_8007D274:\n"
    "lui $1,0x8007\n"
    "lwc1 $f2,4832($1)\n"
    "lui $1,0x8007\n"
    "lwc1 $f4,4836($1)\n"
    "li $2,1\n"
    "sw $2,592($20)\n"
    "swc1 $f0,596($20)\n"
    "swc1 $f2,600($20)\n"
    "jal func_800AE420\n"
    ".end func_8007D274\n.set at\n.set reorder\n");
