/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80097B1C\n.ent func_80097B1C\n"
    "func_80097B1C:\n"
    "lw $5,4($19)\n"
    "jal func_800AB2A4\n"
    "move $7,$17\n"
    "move $4,$17\n"
    "j func_80072568\n"
    "move $5,$0\n"
    ".end func_80097B1C\n.set at\n.set reorder\n");
