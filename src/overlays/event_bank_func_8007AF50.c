/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007AF50\n.ent func_8007AF50\n"
    "func_8007AF50:\n"
    "andi $3,$4,0xff\n"
    "lui $4,0x800f\n"
    "addiu $4,$4,9952\n"
    "li $6,24\n"
    "lui $2,0x800f\n"
    "lw $5,10052($2)\n"
    "move $7,$19\n"
    "sw $0,16($29)\n"
    "jal func_800AB2A4\n"
    "sw $0,20($29)\n"
    "j func_80072930\n"
    "nop\n"
    ".end func_8007AF50\n.set at\n.set reorder\n");
