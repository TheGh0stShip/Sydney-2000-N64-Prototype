/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80074A1C\n.ent func_80074A1C\n"
    "func_80074A1C:\n"
    ".word 0x10400074\n"
    "lui $4,0x800f\n"
    "addiu $4,$4,9952\n"
    "li $6,21\n"
    "sw $0,16($29)\n"
    "sw $0,20($29)\n"
    "lw $5,4($30)\n"
    "j func_80071888\n"
    "move $7,$18\n"
    ".end func_80074A1C\n.set at\n.set reorder\n");
