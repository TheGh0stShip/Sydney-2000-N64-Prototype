/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007BE74\n.ent func_8007BE74\n"
    "func_8007BE74:\n"
    "lbu $3,3224($18)\n"
    "lw $7,3260($18)\n"
    "lbu $4,3225($18)\n"
    "addu $7,$7,$3\n"
    "sll $2,$3,0x2\n"
    "addu $2,$2,$3\n"
    "addu $2,$2,$4\n"
    "sll $2,$2,0x4\n"
    "lw $3,3256($18)\n"
    ".end func_8007BE74\n.set at\n.set reorder\n");
