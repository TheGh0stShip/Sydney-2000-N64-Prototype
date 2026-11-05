/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80074770\n.ent func_80074770\n"
    "func_80074770:\n"
    "sw $2,2824($4)\n"
    "li $2,15360\n"
    "sw $2,1216($18)\n"
    "li $2,25\n"
    "sw $2,1552($18)\n"
    "lbu $2,2822($4)\n"
    "sw $0,2844($4)\n"
    "addiu $2,$2,1\n"
    ".end func_80074770\n.set at\n.set reorder\n");
