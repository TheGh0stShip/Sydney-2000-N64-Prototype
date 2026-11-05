/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80074A70\n.ent func_80074A70\n"
    "func_80074A70:\n"
    "lui $2,0x800f\n"
    "addiu $16,$2,10960\n"
    "lbu $5,17($30)\n"
    "jal func_800BC07C\n"
    "move $4,$16\n"
    "lui $2,0x1\n"
    "addu $2,$18,$2\n"
    "lbu $3,17($30)\n"
    "lw $2,3400($2)\n"
    ".word 0x14400014\n"
    "srl $3,$3,0x5\n"
    "lbu $4,3($16)\n"
    ".end func_80074A70\n.set at\n.set reorder\n");
