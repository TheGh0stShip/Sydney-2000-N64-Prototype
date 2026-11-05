/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80075F94\n.ent func_80075F94\n"
    "func_80075F94:\n"
    "lui $6,0x1\n"
    "lw $16,0($17)\n"
    ".word 0x12000011\n"
    "lui $6,0x1\n"
    "lw $2,4($17)\n"
    "beqz $2,L_80075FBC\n"
    "sw $0,0($17)\n"
    "move $4,$16\n"
    "jal func_800AA658\n"
    "addiu $5,$17,4\n"
    "L_80075FBC:\n"
    "lw $2,8($17)\n"
    ".word 0x10400003\n"
    "move $4,$16\n"
    ".end func_80075F94\n.set at\n.set reorder\n");
