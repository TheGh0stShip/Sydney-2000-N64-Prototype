/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007B3AC\n.ent func_8007B3AC\n"
    "func_8007B3AC:\n"
    ".word 0x1040002D\n"
    "sll $2,$3,0x4\n"
    "subu $2,$2,$3\n"
    "sll $2,$2,0x2\n"
    "addu $2,$4,$2\n"
    "lbu $17,32($2)\n"
    "li $2,2\n"
    ".end func_8007B3AC\n.set at\n.set reorder\n");
