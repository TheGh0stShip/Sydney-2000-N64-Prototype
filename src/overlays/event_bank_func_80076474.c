/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076474\n.ent func_80076474\n"
    "func_80076474:\n"
    ".word 0x10400003\n"
    "move $4,$17\n"
    "jal func_800AA658\n"
    ".end func_80076474\n.set at\n.set reorder\n");
