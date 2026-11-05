/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007517C\n.ent func_8007517C\n"
    "func_8007517C:\n"
    "addu $4,$18,$4\n"
    "lui $16,0x1\n"
    "addu $16,$18,$16\n"
    "jal func_800D29E0\n"
    "sw $0,2832($16)\n"
    "addiu $4,$18,1584\n"
    ".end func_8007517C\n.set at\n.set reorder\n");
