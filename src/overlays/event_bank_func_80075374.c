/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80075374\n.ent func_80075374\n"
    "func_80075374:\n"
    "jal func_80083298\n"
    "li $5,20\n"
    "move $4,$18\n"
    "li $5,38\n"
    "move $6,$0\n"
    "jal func_80075F94\n"
    "move $7,$6\n"
    "li $2,0xd200\n"
    "sw $17,2832($16)\n"
    "sw $2,1216($18)\n"
    "j func_8007254C\n"
    "li $2,22\n"
    ".end func_80075374\n.set at\n.set reorder\n");
