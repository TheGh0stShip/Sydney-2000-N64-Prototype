/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800D2424\n.ent func_800D2424\n"
    "func_800D2424:\n"
    "sw $0,16($29)\n"
    "lui $4,0x800f\n"
    "addiu $4,$4,10968\n"
    "li $5,12\n"
    "li $6,1\n"
    "jal func_800BBD78\n"
    "move $7,$16\n"
    "j func_80070B38\n"
    "nop\n"
    ".end func_800D2424\n.set at\n.set reorder\n");
