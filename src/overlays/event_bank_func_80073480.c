/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80073480\n.ent func_80073480\n"
    "func_80073480:\n"
    "addiu $4,$17,4004\n"
    "move $5,$16\n"
    "li $6,1\n"
    "move $7,$19\n"
    "jal func_800A9B78\n"
    "sw $2,16($29)\n"
    ".end func_80073480\n.set at\n.set reorder\n");
