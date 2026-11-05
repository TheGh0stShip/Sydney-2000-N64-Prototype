/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80075194\n.ent func_80075194\n"
    "func_80075194:\n"
    "jal func_80083298\n"
    "li $5,21\n"
    "li $2,0xf600\n"
    "sw $0,2832($16)\n"
    "sw $2,1216($18)\n"
    "j func_8007254C\n"
    "li $2,17\n"
    ".end func_80075194\n.set at\n.set reorder\n");
