/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80073CF0\n.ent func_80073CF0\n"
    "func_80073CF0:\n"
    "move $4,$17\n"
    "lw $2,192($17)\n"
    "move $5,$19\n"
    "ori $2,$2,0x600\n"
    "and $2,$2,$18\n"
    "jal func_800AD890\n"
    "sw $2,192($17)\n"
    "jal func_800ADC38\n"
    "move $4,$17\n"
    "move $4,$17\n"
    "jal func_800AC37C\n"
    "move $5,$30\n"
    "addiu $16,$30,3568\n"
    "lb $2,10337($30)\n"
    ".end func_80073CF0\n.set at\n.set reorder\n");
