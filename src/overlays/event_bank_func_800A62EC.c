/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800A62EC\n.ent func_800A62EC\n"
    "func_800A62EC:\n"
    "sll $2,$3,0x4\n"
    "subu $2,$2,$3\n"
    "sll $2,$2,0x2\n"
    "addu $2,$5,$2\n"
    "lbu $3,32($2)\n"
    "j func_80075310\n"
    "li $2,3\n"
    ".end func_800A62EC\n.set at\n.set reorder\n");
