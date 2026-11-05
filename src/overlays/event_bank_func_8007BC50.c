/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007BC50\n.ent func_8007BC50\n"
    "func_8007BC50:\n"
    "jal func_8007D8A4\n"
    "addu $5,$2,$5\n"
    "lw $4,21356($19)\n"
    "jal func_8007B194\n"
    "li $5,1\n"
    "lbu $2,3229($18)\n"
    ".word 0x1050000A\n"
    "sw $16,3220($18)\n"
    "lui $4,0x800f\n"
    "addiu $4,$4,6880\n"
    "move $6,$0\n"
    "li $7,270\n"
    "lw $5,17976($18)\n"
    "li $2,1\n"
    ".end func_8007BC50\n.set at\n.set reorder\n");
