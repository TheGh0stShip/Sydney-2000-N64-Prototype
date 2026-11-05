/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007293C\n.ent func_8007293C\n"
    "func_8007293C:\n"
    "lui $7,0x3f80\n"
    "li $6,-1\n"
    "sw $0,16($29)\n"
    "sw $3,10004($22)\n"
    "mflo $8\n"
    "srl $2,$8,0x10\n"
    "sll $2,$2,0x2\n"
    "lui $8,0x8007\n"
    ".end func_8007293C\n.set at\n.set reorder\n");
