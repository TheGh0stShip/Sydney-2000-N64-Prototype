/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076FF0\n.ent func_80076FF0\n"
    "func_80076FF0:\n"
    "addiu $2,$4,-2\n"
    "sltiu $2,$2,4\n"
    ".word 0x1040006A\n"
    "andi $2,$6,0xff\n"
    "addu $2,$18,$2\n"
    "addu $2,$2,$10\n"
    "lbu $2,3364($2)\n"
    "sltu $2,$2,$3\n"
    ".word 0x14400064\n"
    "nop\n"
    "jal func_800743AC\n"
    "move $4,$18\n"
    "j func_80073E44\n"
    "nop\n"
    ".end func_80076FF0\n.set at\n.set reorder\n");
