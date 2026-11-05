/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800726C4\n.ent func_800726C4\n"
    "func_800726C4:\n"
    "sw $0,16($29)\n"
    "sll $2,$5,0x2\n"
    "addu $2,$2,$5\n"
    "sll $3,$2,0x4\n"
    "subu $3,$3,$2\n"
    "sll $3,$3,0x5\n"
    "addu $3,$3,$5\n"
    "sll $2,$3,0x3\n"
    "subu $2,$2,$3\n"
    "and $2,$2,$20\n"
    "sw $2,10004($17)\n"
    "srl $2,$2,0x1e\n"
    "sll $2,$2,0x2\n"
    ".end func_800726C4\n.set at\n.set reorder\n");
