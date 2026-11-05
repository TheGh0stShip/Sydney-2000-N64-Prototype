/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80075FC8\n.ent func_80075FC8\n"
    "func_80075FC8:\n"
    "jal func_800AA658\n"
    "addiu $5,$17,8\n"
    "sh $0,16($17)\n"
    "sh $0,18($17)\n"
    "sw $0,12($17)\n"
    "sw $0,0($17)\n"
    "lui $6,0x1\n"
    "ori $6,$6,0xca8\n"
    "lui $17,0x1\n"
    "ori $17,$17,0xb20\n"
    "addu $17,$20,$17\n"
    ".end func_80075FC8\n.set at\n.set reorder\n");
