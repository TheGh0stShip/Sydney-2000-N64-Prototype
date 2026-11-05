/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80074588\n.ent func_80074588\n"
    "func_80074588:\n"
    "addu $2,$18,$2\n"
    "j func_8007127C\n"
    "sb $20,3384($2)\n"
    ".end func_80074588\n.set at\n.set reorder\n");
