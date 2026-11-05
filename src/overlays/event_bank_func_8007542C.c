/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007542C\n.ent func_8007542C\n"
    "func_8007542C:\n"
    "li $2,26\n"
    "lw $2,1216($18)\n"
    "addiu $2,$2,-256\n"
    ".word 0x1C40011D\n"
    ".end func_8007542C\n.set at\n.set reorder\n");
