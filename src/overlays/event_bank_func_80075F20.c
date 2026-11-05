/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80075F20\n.ent func_80075F20\n"
    "func_80075F20:\n"
    "addiu $7,$7,2000\n"
    "sw $19,352($16)\n"
    "jal func_800AA804\n"
    "sh $18,16($17)\n"
    ".end func_80075F20\n.set at\n.set reorder\n");
