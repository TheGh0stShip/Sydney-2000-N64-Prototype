/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80083944\n.ent func_80083944\n"
    "func_80083944:\n"
    "addiu $29,$29,-48\n"
    "sw $18,32($29)\n"
    "move $18,$4\n"
    "sw $31,40($29)\n"
    "sw $19,36($29)\n"
    "sw $17,28($29)\n"
    ".word 0x10A0035B\n"
    "sw $16,24($29)\n"
    "lw $3,21564($18)\n"
    "li $2,1\n"
    ".word 0x14620008\n"
    "lui $3,0x800f\n"
    "lw $2,10112($3)\n"
    "addiu $2,$2,-256\n"
    ".end func_80083944\n.set at\n.set reorder\n");
