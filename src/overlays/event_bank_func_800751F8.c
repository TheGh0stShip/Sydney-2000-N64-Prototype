/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800751F8\n.ent func_800751F8\n"
    "func_800751F8:\n"
    "li $5,18\n"
    "move $4,$18\n"
    "li $5,35\n"
    "move $6,$0\n"
    "jal func_80075F94\n"
    "move $7,$6\n"
    "lui $2,0x1\n"
    "ori $2,$2,0x2c00\n"
    "sw $17,2832($16)\n"
    "sw $2,1216($18)\n"
    ".end func_800751F8\n.set at\n.set reorder\n");
