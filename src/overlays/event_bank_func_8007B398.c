/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007B398\n.ent func_8007B398\n"
    "func_8007B398:\n"
    "addu $2,$2,$3\n"
    "sll $2,$2,0x2\n"
    "addu $2,$4,$2\n"
    "lb $3,2576($2)\n"
    "slti $2,$3,8\n"
    ".end func_8007B398\n.set at\n.set reorder\n");
