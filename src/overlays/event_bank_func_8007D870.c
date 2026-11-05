/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007D870\n.ent func_8007D870\n"
    "func_8007D870:\n"
    "sll $4,$2,0x5\n"
    "subu $4,$4,$2\n"
    "sll $4,$4,0x4\n"
    "addu $4,$4,$17\n"
    "jal func_800A1070\n"
    "addu $4,$20,$4\n"
    "addiu $16,$16,1\n"
    "andi $2,$16,0xff\n"
    "sltiu $2,$2,11\n"
    "bnez $2,func_8007D870\n"
    "andi $2,$16,0xff\n"
    "li $2,0x8000\n"
    "addu $2,$20,$2\n"
    ".end func_8007D870\n.set at\n.set reorder\n");
