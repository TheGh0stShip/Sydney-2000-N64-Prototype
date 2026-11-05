/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80071480\n.ent func_80071480\n"
    "func_80071480:\n"
    "lwc1 $f0,8($2)\n"
    "move $7,$17\n"
    "jal func_800A851C\n"
    "swc1 $f0,8($16)\n"
    "j func_800718BC\n"
    "andi $18,$23,0xff\n"
    ".end func_80071480\n.set at\n.set reorder\n");
