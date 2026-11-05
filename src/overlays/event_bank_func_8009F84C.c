/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8009F84C\n.ent func_8009F84C\n"
    "func_8009F84C:\n"
    "lbu $3,426($17)\n"
    "li $2,4\n"
    "beq $3,$2,L_8009F874\n"
    "nop\n"
    "lw $2,23712($18)\n"
    "lw $4,728($2)\n"
    "jal func_8001786C\n"
    "nop\n"
    "jal func_80017B0C\n"
    "li $4,2\n"
    "L_8009F874:\n"
    "lbu $5,424($17)\n"
    "li $2,8\n"
    ".word 0x10A20007\n"
    ".end func_8009F84C\n.set at\n.set reorder\n");
