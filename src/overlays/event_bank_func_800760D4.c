/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800760D4\n.ent func_800760D4\n"
    "func_800760D4:\n"
    "lui $4,0x800f\n"
    "addiu $4,$4,9952\n"
    "li $6,21\n"
    "lui $2,0x800f\n"
    "lw $5,10052($2)\n"
    "move $7,$20\n"
    "sw $0,16($29)\n"
    "jal func_800AB2A4\n"
    "sw $0,20($29)\n"
    ".end func_800760D4\n.set at\n.set reorder\n");
