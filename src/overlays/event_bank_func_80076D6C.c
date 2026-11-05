/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076D6C\n.ent func_80076D6C\n"
    "func_80076D6C:\n"
    "jal func_800AC25C\n"
    "sw $17,3416($2)\n"
    "li $2,0x9600\n"
    "sw $2,1216($18)\n"
    "li $2,8\n"
    "j func_80073A2C\n"
    ".end func_80076D6C\n.set at\n.set reorder\n");
