/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076C78\n.ent func_80076C78\n"
    "func_80076C78:\n"
    "ori $4,$4,0x3c8\n"
    "jal func_800D29E0\n"
    "addu $4,$18,$4\n"
    "jal func_80075610\n"
    "move $4,$18\n"
    "j func_80073A2C\n"
    "nop\n"
    ".end func_80076C78\n.set at\n.set reorder\n");
