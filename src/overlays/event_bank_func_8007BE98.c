/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007BE98\n.ent func_8007BE98\n"
    "func_8007BE98:\n"
    "lbu $7,0($7)\n"
    "addu $3,$3,$2\n"
    "lui $2,0x800f\n"
    "addiu $2,$2,19712\n"
    "addiu $2,$2,220\n"
    "sw $3,16($29)\n"
    "sw $2,20($29)\n"
    "lw $4,21356($19)\n"
    "jal func_8007DAA4\n"
    "move $6,$0\n"
    "li $2,0x8000\n"
    "addu $2,$19,$2\n"
    "lbu $3,3229($2)\n"
    ".end func_8007BE98\n.set at\n.set reorder\n");
