/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80074FB4\n.ent func_80074FB4\n"
    "func_80074FB4:\n"
    "addu $4,$18,$4\n"
    "lui $16,0x1\n"
    "addu $16,$18,$16\n"
    "jal func_800D29E0\n"
    "sw $0,2832($16)\n"
    "li $2,10\n"
    "j func_8007254C\n"
    "sw $0,2832($16)\n"
    ".end func_80074FB4\n.set at\n.set reorder\n");
