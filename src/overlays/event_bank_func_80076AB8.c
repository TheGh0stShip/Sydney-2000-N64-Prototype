/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076AB8\n.ent func_80076AB8\n"
    "func_80076AB8:\n"
    "andi $7,$20,0xff\n"
    "sw $0,16($29)\n"
    "jal func_800818F0\n"
    "sw $6,20($29)\n"
    "j func_80073608\n"
    "nop\n"
    ".end func_80076AB8\n.set at\n.set reorder\n");
