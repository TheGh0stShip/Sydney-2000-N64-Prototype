/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076944\n.ent func_80076944\n"
    "func_80076944:\n"
    "lui $3,0x800f\n"
    "sw $31,56($29)\n"
    "sw $23,52($29)\n"
    "sw $20,40($29)\n"
    "sw $17,28($29)\n"
    "sw $16,24($29)\n"
    "lbu $2,2573($2)\n"
    "addiu $23,$3,10864\n"
    ".end func_80076944\n.set at\n.set reorder\n");
