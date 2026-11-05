/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007716C\n.ent func_8007716C\n"
    "func_8007716C:\n"
    "jal func_8009D854\n"
    "move $4,$17\n"
    "andi $2,$19,0xff\n"
    "addu $2,$18,$2\n"
    "lui $3,0x1\n"
    "addu $2,$2,$3\n"
    "lbu $7,3364($2)\n"
    "move $4,$18\n"
    "sw $20,16($29)\n"
    "lw $5,24($29)\n"
    "lw $6,28($29)\n"
    "addiu $7,$7,-1\n"
    ".end func_8007716C\n.set at\n.set reorder\n");
