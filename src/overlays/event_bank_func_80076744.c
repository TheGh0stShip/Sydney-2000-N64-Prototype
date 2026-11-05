/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076744\n.ent func_80076744\n"
    "func_80076744:\n"
    "jal func_800761BC\n"
    "sw $0,2844($16)\n"
    "li $5,1\n"
    "sw $5,172($19)\n"
    "lbu $2,2820($16)\n"
    ".end func_80076744\n.set at\n.set reorder\n");
