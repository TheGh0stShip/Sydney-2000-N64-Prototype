/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800750AC\n.ent func_800750AC\n"
    "func_800750AC:\n"
    "sw $2,1216($18)\n"
    "li $2,15\n"
    "sw $2,1552($18)\n"
    "lui $2,0x1\n"
    "addu $2,$18,$2\n"
    "li $3,1\n"
    "sw $3,2844($2)\n"
    "jal func_80075F4C\n"
    "move $4,$18\n"
    "j func_80072550\n"
    "nop\n"
    ".end func_800750AC\n.set at\n.set reorder\n");
