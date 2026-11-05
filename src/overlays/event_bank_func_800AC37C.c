/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800AC37C\n.ent func_800AC37C\n"
    "func_800AC37C:\n"
    "beqz $2,L_800AC38C\n"
    "move $4,$16\n"
    "jal func_800AA658\n"
    "addiu $5,$17,8\n"
    "L_800AC38C:\n"
    "sh $0,16($17)\n"
    "sh $0,18($17)\n"
    "sw $0,12($17)\n"
    "sw $0,0($17)\n"
    "lui $4,0x800f\n"
    "addiu $4,$4,10072\n"
    ".end func_800AC37C\n.set at\n.set reorder\n");
