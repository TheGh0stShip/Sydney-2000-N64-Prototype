/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007BD9C\n.ent func_8007BD9C\n"
    "func_8007BD9C:\n"
    "li $2,0x8000\n"
    "addu $4,$19,$4\n"
    "jal func_800A9BE8\n"
    "li $5,2\n"
    "j func_80072C34\n"
    "li $2,0x8000\n"
    ".end func_8007BD9C\n.set at\n.set reorder\n");
