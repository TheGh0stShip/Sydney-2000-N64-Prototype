/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800ADE84\n.ent func_800ADE84\n"
    "func_800ADE84:\n"
    "mflo $10\n"
    "srl $2,$10,0x10\n"
    "j func_800761D0\n"
    "sltiu $2,$2,30\n"
    ".end func_800ADE84\n.set at\n.set reorder\n");
