/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80075748\n.ent func_80075748\n"
    "func_80075748:\n"
    "addiu $2,$2,-256\n"
    ".word 0x1C400058\n"
    "sw $2,1216($18)\n"
    "li $4,0xd954\n"
    "jal func_800D771C\n"
    "addu $4,$18,$4\n"
    "j func_8007254C\n"
    "li $2,30\n"
    ".end func_80075748\n.set at\n.set reorder\n");
