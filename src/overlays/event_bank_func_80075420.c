/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80075420\n.ent func_80075420\n"
    "func_80075420:\n"
    "li $2,0x9600\n"
    "sw $2,1216($18)\n"
    "j func_8007254C\n"
    ".end func_80075420\n.set at\n.set reorder\n");
