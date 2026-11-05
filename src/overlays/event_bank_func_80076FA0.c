/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076FA0\n.ent func_80076FA0\n"
    "func_80076FA0:\n"
    "swc1 $f0,3316($3)\n"
    "lbu $2,3364($9)\n"
    "addiu $3,$2,1\n"
    "andi $2,$2,0xff\n"
    "sll $2,$2,0x2\n"
    "addu $2,$2,$4\n"
    ".end func_80076FA0\n.set at\n.set reorder\n");
