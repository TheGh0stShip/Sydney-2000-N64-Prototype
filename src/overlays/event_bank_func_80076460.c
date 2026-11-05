/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076460\n.ent func_80076460\n"
    "func_80076460:\n"
    "sw $0,9904($19)\n"
    "move $4,$17\n"
    "jal func_800AA658\n"
    "addiu $5,$16,4\n"
    "lw $2,8($16)\n"
    ".end func_80076460\n.set at\n.set reorder\n");
