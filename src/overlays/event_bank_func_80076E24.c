/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076E24\n.ent func_80076E24\n"
    "func_80076E24:\n"
    "lui $16,0x1\n"
    "addu $16,$18,$16\n"
    "sw $19,3396($16)\n"
    "lbu $5,425($17)\n"
    "lbu $6,424($17)\n"
    "jal func_8009A828\n"
    "addiu $4,$18,29012\n"
    "lwc1 $f0,3368($16)\n"
    "swc1 $f0,3376($16)\n"
    "lwc1 $f0,3372($16)\n"
    "lwc1 $f2,3376($16)\n"
    ".end func_80076E24\n.set at\n.set reorder\n");
