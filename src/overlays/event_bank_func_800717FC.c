/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800717FC\n.ent func_800717FC\n"
    "func_800717FC:\n"
    "addu $16,$16,$19\n"
    "sll $16,$16,0x2\n"
    "addiu $2,$16,1724\n"
    "addu $22,$21,$2\n"
    "move $4,$22\n"
    "jal func_800AD890\n"
    "li $5,1\n"
    "addu $6,$16,$21\n"
    "addiu $6,$6,1724\n"
    ".end func_800717FC\n.set at\n.set reorder\n");
