/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80072078\n.ent func_80072078\n"
    "func_80072078:\n"
    "sw $16,16($29)\n"
    "lbu $2,4456($19)\n"
    "beqz $2,L_8007209C\n"
    "lui $16,0x800f\n"
    "lui $4,0x800f\n"
    "addiu $4,$4,9972\n"
    "jal func_800AB934\n"
    "move $5,$19\n"
    "lui $16,0x800f\n"
    "L_8007209C:\n"
    "addiu $16,$16,15296\n"
    "jal func_800C013C\n"
    "move $4,$16\n"
    ".end func_80072078\n.set at\n.set reorder\n");
