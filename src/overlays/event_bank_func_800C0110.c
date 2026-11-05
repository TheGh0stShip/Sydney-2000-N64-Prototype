/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800C0110\n.ent func_800C0110\n"
    "func_800C0110:\n"
    "jal func_800AD890\n"
    "li $5,1\n"
    "lw $2,208($16)\n"
    "lui $1,0x8007\n"
    "lwc1 $f0,2544($1)\n"
    "lw $2,8($2)\n"
    "swc1 $f0,40($2)\n"
    "lw $31,28($29)\n"
    "lw $16,24($29)\n"
    "jr $31\n"
    "addiu $29,$29,32\n"
    ".end func_800C0110\n.set at\n.set reorder\n");
