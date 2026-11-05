/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80074E28\n.ent func_80074E28\n"
    "func_80074E28:\n"
    "lui $2,0x1\n"
    "addu $2,$18,$2\n"
    "lbu $2,2841($2)\n"
    "sltiu $2,$2,2\n"
    ".word 0x1440029D\n"
    "nop\n"
    "jal func_800834B0\n"
    "addiu $4,$18,28608\n"
    "j func_80072550\n"
    "nop\n"
    ".end func_80074E28\n.set at\n.set reorder\n");
