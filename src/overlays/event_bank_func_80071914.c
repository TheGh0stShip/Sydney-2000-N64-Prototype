/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80071914\n.ent func_80071914\n"
    "func_80071914:\n"
    "jal func_80017B04\n"
    "move $4,$0\n"
    "li $8,1\n"
    ".word 0x12680034\n"
    "slti $2,$19,2\n"
    ".word 0x10400061\n"
    "nop\n"
    ".word 0x1660005F\n"
    "nop\n"
    "mfc1 $7,$f20\n"
    "lw $5,10004($30)\n"
    "lw $4,60($29)\n"
    ".end func_80071914\n.set at\n.set reorder\n");
