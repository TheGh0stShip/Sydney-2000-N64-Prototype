/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076864\n.ent func_80076864\n"
    "func_80076864:\n"
    "andi $3,$18,0xff\n"
    "sltiu $2,$3,2\n"
    ".word 0x10400020\n"
    "sll $2,$3,0x1\n"
    "addu $2,$2,$3\n"
    "sll $2,$2,0x2\n"
    "addu $2,$2,$3\n"
    ".end func_80076864\n.set at\n.set reorder\n");
