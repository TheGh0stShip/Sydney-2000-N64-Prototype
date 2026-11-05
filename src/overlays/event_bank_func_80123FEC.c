/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80123FEC\n.ent func_80123FEC\n"
    "func_80123FEC:\n"
    "addiu $29,$29,-24\n"
    "li $2,1\n"
    "sw $31,16($29)\n"
    "sb $5,10969($4)\n"
    "sb $6,10970($4)\n"
    "sb $7,10971($4)\n"
    "sw $2,11008($4)\n"
    "jal func_8000673C\n"
    "addiu $4,$4,10968\n"
    "lw $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_80123FEC\n.set at\n.set reorder\n");
