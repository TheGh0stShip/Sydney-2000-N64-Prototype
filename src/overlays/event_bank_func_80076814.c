/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076814\n.ent func_80076814\n"
    "func_80076814:\n"
    "lui $2,0x800f\n"
    "sw $31,36($29)\n"
    "sw $20,32($29)\n"
    "sw $18,24($29)\n"
    ".end func_80076814\n.set at\n.set reorder\n");
