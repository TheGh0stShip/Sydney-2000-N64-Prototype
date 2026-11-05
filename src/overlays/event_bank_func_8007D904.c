/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007D904\n.ent func_8007D904\n"
    "func_8007D904:\n"
    "sltiu $2,$3,8\n"
    ".word 0x1440FFFC\n"
    "addiu $4,$4,4\n"
    ".end func_8007D904\n.set at\n.set reorder\n");
