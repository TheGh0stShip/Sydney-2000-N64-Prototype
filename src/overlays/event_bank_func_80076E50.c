/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076E50\n.ent func_80076E50\n"
    "func_80076E50:\n"
    "li $2,2\n"
    "sb $2,2841($16)\n"
    "swc1 $f0,3380($16)\n"
    "swc1 $f2,3384($16)\n"
    "lw $31,40($29)\n"
    "lw $19,36($29)\n"
    "lw $18,32($29)\n"
    ".end func_80076E50\n.set at\n.set reorder\n");
