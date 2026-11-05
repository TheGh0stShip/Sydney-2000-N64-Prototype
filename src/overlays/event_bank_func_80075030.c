/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80075030\n.ent func_80075030\n"
    "func_80075030:\n"
    "jal func_80075F94\n"
    "move $7,$6\n"
    "move $4,$17\n"
    "li $5,16\n"
    "lui $2,0x1\n"
    "addu $2,$18,$2\n"
    "li $3,1\n"
    "sw $3,2832($2)\n"
    ".end func_80075030\n.set at\n.set reorder\n");
