/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076BB4\n.ent func_80076BB4\n"
    "func_80076BB4:\n"
    "sw $2,2824($16)\n"
    "li $2,26\n"
    "sw $0,2832($16)\n"
    "sw $0,1216($18)\n"
    "jal func_800C013C\n"
    "sw $2,1552($18)\n"
    "j func_80073A2C\n"
    "nop\n"
    ".end func_80076BB4\n.set at\n.set reorder\n");
