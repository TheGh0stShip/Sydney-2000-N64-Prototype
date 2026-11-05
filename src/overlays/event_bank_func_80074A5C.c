/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80074A5C\n.ent func_80074A5C\n"
    "func_80074A5C:\n"
    "sw $0,16($29)\n"
    "sw $2,20($29)\n"
    "lw $5,4($30)\n"
    "j func_80071888\n"
    "move $7,$18\n"
    ".end func_80074A5C\n.set at\n.set reorder\n");
