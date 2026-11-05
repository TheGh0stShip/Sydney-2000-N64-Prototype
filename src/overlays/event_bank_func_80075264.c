/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80075264\n.ent func_80075264\n"
    "func_80075264:\n"
    "ori $2,$2,0xda00\n"
    "sw $2,1216($18)\n"
    "j func_8007254C\n"
    "li $2,19\n"
    ".end func_80075264\n.set at\n.set reorder\n");
