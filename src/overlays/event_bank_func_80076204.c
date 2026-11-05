/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076204\n.ent func_80076204\n"
    "func_80076204:\n"
    "sw $3,5104($5)\n"
    "srl $3,$3,0x1e\n"
    ".end func_80076204\n.set at\n.set reorder\n");
