/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007BD64\n.ent func_8007BD64\n"
    "func_8007BD64:\n"
    "jal func_800D29E0\n"
    "addiu $4,$19,14600\n"
    "jal func_800D29E0\n"
    "addiu $4,$19,16000\n"
    "jal func_800D29E0\n"
    "addiu $4,$19,17400\n"
    "lw $2,21356($19)\n"
    "lbu $2,896($2)\n"
    ".word 0x10400006\n"
    "li $4,0x86f8\n"
    "addu $4,$19,$4\n"
    "jal func_800A9BE8\n"
    "li $5,12\n"
    "j func_80072C34\n"
    ".end func_8007BD64\n.set at\n.set reorder\n");
