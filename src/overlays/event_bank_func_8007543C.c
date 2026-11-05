/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007543C\n.ent func_8007543C\n"
    "func_8007543C:\n"
    "sw $2,1216($18)\n"
    "lui $6,0x7fff\n"
    "lui $5,0x800f\n"
    "lw $4,5104($5)\n"
    ".end func_8007543C\n.set at\n.set reorder\n");
