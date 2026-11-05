/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80077528\n.ent func_80077528\n"
    "func_80077528:\n"
    "addiu $29,$29,-24\n"
    "sw $31,16($29)\n"
    "lbu $2,1556($4)\n"
    "lw $3,40($29)\n"
    "sltiu $2,$2,2\n"
    ".word 0x10400070\n"
    "subu $2,$5,$6\n"
    "sltiu $2,$2,256\n"
    ".word 0x10400017\n"
    ".end func_80077528\n.set at\n.set reorder\n");
