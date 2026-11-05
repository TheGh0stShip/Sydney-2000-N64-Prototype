/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007BD3C\n.ent func_8007BD3C\n"
    "func_8007BD3C:\n"
    "lbu $2,3224($18)\n"
    "lbu $5,3225($18)\n"
    "sll $6,$2,0x2\n"
    "addu $6,$6,$2\n"
    "lw $2,3256($18)\n"
    "sll $6,$6,0x4\n"
    "jal func_800CFE1C\n"
    ".end func_8007BD3C\n.set at\n.set reorder\n");
