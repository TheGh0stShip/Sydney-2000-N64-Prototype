/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80073230\n.ent func_80073230\n"
    "func_80073230:\n"
    "jal func_800AC5CC\n"
    "li $7,1\n"
    "jal func_800AD9E8\n"
    "move $4,$17\n"
    "j func_800735B4\n"
    "andi $18,$21,0xff\n"
    ".end func_80073230\n.set at\n.set reorder\n");
