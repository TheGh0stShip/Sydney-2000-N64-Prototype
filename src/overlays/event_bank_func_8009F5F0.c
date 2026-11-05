/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8009F5F0\n.ent func_8009F5F0\n"
    "func_8009F5F0:\n"
    "addiu $21,$21,1\n"
    "jal func_8000C944\n"
    "nop\n"
    "jal func_800D16E0\n"
    ".end func_8009F5F0\n.set at\n.set reorder\n");
