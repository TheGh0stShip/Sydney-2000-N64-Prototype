/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80078188\n.ent func_80078188\n"
    "func_80078188:\n"
    "addiu $29,$29,-24\n"
    "sw $31,16($29)\n"
    "lbu $2,1556($4)\n"
    ".word 0x144001F3\n"
    "lui $2,0x1\n"
    ".end func_80078188\n.set at\n.set reorder\n");
