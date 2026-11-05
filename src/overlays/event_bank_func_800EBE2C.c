/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800EBE2C\n.ent func_800EBE2C\n"
    "func_800EBE2C:\n"
    "sb $0,3($2)\n"
    "sb $0,4($2)\n"
    "sb $0,5($2)\n"
    "sb $0,6($2)\n"
    "sb $0,7($2)\n"
    "sw $0,16($29)\n"
    "sw $0,20($29)\n"
    "lw $5,892($16)\n"
    "lw $7,632($16)\n"
    "jal func_800B9FA4\n"
    "li $6,-1\n"
    ".end func_800EBE2C\n.set at\n.set reorder\n");
