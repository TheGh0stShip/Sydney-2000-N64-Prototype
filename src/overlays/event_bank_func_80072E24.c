/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80072E24\n.ent func_80072E24\n"
    "func_80072E24:\n"
    "lui $2,0x800f\n"
    "lw $5,10052($2)\n"
    "move $7,$19\n"
    "sw $0,16($29)\n"
    "jal func_800AB2A4\n"
    "sw $0,20($29)\n"
    "move $18,$0\n"
    "li $21,1\n"
    "lui $17,0x800f\n"
    "lui $20,0x7fff\n"
    "ori $20,$20,0xffff\n"
    ".end func_80072E24\n.set at\n.set reorder\n");
