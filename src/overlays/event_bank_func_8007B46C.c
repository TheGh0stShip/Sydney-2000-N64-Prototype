/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007B46C\n.ent func_8007B46C\n"
    "func_8007B46C:\n"
    "li $2,0x8000\n"
    "lbu $2,3410($4)\n"
    "andi $2,$2,0x3\n"
    ".word 0x10400017\n"
    "move $4,$19\n"
    "jal func_800751CC\n"
    "move $5,$0\n"
    "jal func_800764C4\n"
    "move $4,$19\n"
    "move $4,$19\n"
    "li $5,1\n"
    "li $2,13\n"
    "jal func_8007311C\n"
    "sw $2,3220($16)\n"
    ".end func_8007B46C\n.set at\n.set reorder\n");
