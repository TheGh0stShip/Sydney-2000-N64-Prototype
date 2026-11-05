/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800CCE4C\n.ent func_800CCE4C\n"
    "func_800CCE4C:\n"
    "sw $17,20($29)\n"
    "jal func_80081C40\n"
    "sw $16,16($29)\n"
    "lui $2,0x8007\n"
    "addiu $2,$2,2392\n"
    "addiu $4,$18,17140\n"
    "jal func_800ADED4\n"
    "sw $2,180($18)\n"
    "addiu $17,$18,17408\n"
    "li $16,4\n"
    "li $19,-1\n"
    "jal func_800ADED4\n"
    "move $4,$17\n"
    "addiu $16,$16,-1\n"
    ".end func_800CCE4C\n.set at\n.set reorder\n");
