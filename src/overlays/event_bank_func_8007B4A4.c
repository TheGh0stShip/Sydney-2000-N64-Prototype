/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007B4A4\n.ent func_8007B4A4\n"
    "func_8007B4A4:\n"
    "lui $16,0x800f\n"
    "addiu $16,$16,10968\n"
    "jal func_800BC180\n"
    "move $4,$16\n"
    "move $4,$16\n"
    "li $5,13\n"
    "li $6,1\n"
    "move $7,$19\n"
    "li $2,2\n"
    "jal func_800BBD78\n"
    "sw $2,16($29)\n"
    "j func_80072270\n"
    "li $2,0x8000\n"
    ".end func_8007B4A4\n.set at\n.set reorder\n");
