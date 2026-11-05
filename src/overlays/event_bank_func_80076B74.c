/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076B74\n.ent func_80076B74\n"
    "func_80076B74:\n"
    "lui $2,0x800f\n"
    "move $7,$18\n"
    "lw $5,10052($2)\n"
    "li $2,9\n"
    "sw $0,16($29)\n"
    "jal func_800AB2A4\n"
    "sw $2,20($29)\n"
    "lbu $3,1556($18)\n"
    ".end func_80076B74\n.set at\n.set reorder\n");
