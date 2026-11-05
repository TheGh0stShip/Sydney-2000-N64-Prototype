/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007B910\n.ent func_8007B910\n"
    "func_8007B910:\n"
    "li $3,1\n"
    "sb $0,185($2)\n"
    "sb $3,184($2)\n"
    "sb $3,186($2)\n"
    "sb $0,187($2)\n"
    "lw $2,21356($19)\n"
    "lbu $2,896($2)\n"
    ".word 0x10400004\n"
    "li $4,0x86f8\n"
    "addu $4,$19,$4\n"
    "j func_800726B8\n"
    ".end func_8007B910\n.set at\n.set reorder\n");
