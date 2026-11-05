/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800CCD10\n.ent func_800CCD10\n"
    "func_800CCD10:\n"
    "sw $0,20($29)\n"
    "sh $0,4548($19)\n"
    "jal func_80082618\n"
    "move $4,$19\n"
    "li $2,30720\n"
    "sw $2,3852($19)\n"
    "li $2,7\n"
    "sw $2,17352($19)\n"
    "j func_80071E58\n"
    "sw $0,3860($19)\n"
    ".end func_800CCD10\n.set at\n.set reorder\n");
