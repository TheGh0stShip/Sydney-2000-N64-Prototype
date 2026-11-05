/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80075DF4\n.ent func_80075DF4\n"
    "func_80075DF4:\n"
    "jal func_800AA658\n"
    "addiu $5,$16,4\n"
    "lw $2,8($16)\n"
    ".word 0x50400005\n"
    "sh $0,16($16)\n"
    "move $4,$17\n"
    "jal func_800AA658\n"
    ".end func_80075DF4\n.set at\n.set reorder\n");
