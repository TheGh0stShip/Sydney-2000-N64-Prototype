/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80074DB0\n.ent func_80074DB0\n"
    "func_80074DB0:\n"
    "jal func_80083440\n"
    "addiu $4,$18,1584\n"
    "lbu $2,2841($16)\n"
    "sltiu $2,$2,2\n"
    ".word 0x144002BB\n"
    "nop\n"
    "jal func_80083440\n"
    "addiu $4,$18,28608\n"
    ".end func_80074DB0\n.set at\n.set reorder\n");
