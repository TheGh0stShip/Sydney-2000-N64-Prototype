/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007572C\n.ent func_8007572C\n"
    "func_8007572C:\n"
    "srl $3,$3,0x1e\n"
    "sb $3,3385($16)\n"
    "jal func_800AC25C\n"
    "sb $0,3386($16)\n"
    "j func_80072550\n"
    "nop\n"
    ".end func_8007572C\n.set at\n.set reorder\n");
