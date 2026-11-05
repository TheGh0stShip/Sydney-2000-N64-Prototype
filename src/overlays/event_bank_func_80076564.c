/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076564\n.ent func_80076564\n"
    "func_80076564:\n"
    "sh $20,0($3)\n"
    "addiu $6,$6,1\n"
    "andi $2,$6,0xff\n"
    "slt $2,$2,$5\n"
    ".end func_80076564\n.set at\n.set reorder\n");
