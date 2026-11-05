/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800ACF20\n.ent func_800ACF20\n"
    "func_800ACF20:\n"
    "addu $5,$5,$6\n"
    "jal func_80075264\n"
    "subu $5,$2,$5\n"
    "jal func_80075AEC\n"
    "move $4,$17\n"
    "lbu $2,284($16)\n"
    "addiu $2,$2,1\n"
    "j func_80075134\n"
    "sb $2,284($16)\n"
    ".end func_800ACF20\n.set at\n.set reorder\n");
