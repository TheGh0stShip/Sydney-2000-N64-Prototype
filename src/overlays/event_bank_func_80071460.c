/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80071460\n.ent func_80071460\n"
    "func_80071460:\n"
    "sll $2,$2,0x2\n"
    "addu $2,$2,$19\n"
    "lwc1 $f0,0($2)\n"
    "move $5,$18\n"
    "swc1 $f0,0($16)\n"
    "lwc1 $f0,4($2)\n"
    "addiu $6,$21,452\n"
    "swc1 $f0,4($16)\n"
    ".end func_80071460\n.set at\n.set reorder\n");
