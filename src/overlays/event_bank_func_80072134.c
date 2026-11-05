/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80072134\n.ent func_80072134\n"
    "func_80072134:\n"
    "lh $4,24($2)\n"
    "lw $2,28($2)\n"
    "jalr $2\n"
    "addu $4,$16,$4\n"
    "andi $2,$18,0xff\n"
    "sltiu $2,$2,3\n"
    ".word 0x1440FFE7\n"
    "andi $2,$18,0xff\n"
    "jal func_800AEFA0\n"
    ".end func_80072134\n.set at\n.set reorder\n");
