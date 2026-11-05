/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800755FC\n.ent func_800755FC\n"
    "func_800755FC:\n"
    "move $7,$18\n"
    "lw $5,10052($2)\n"
    "move $2,$6\n"
    "sw $0,16($29)\n"
    "jal func_800AB2A4\n"
    ".end func_800755FC\n.set at\n.set reorder\n");
