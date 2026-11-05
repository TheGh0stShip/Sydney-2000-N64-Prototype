/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800ADE10\n.ent func_800ADE10\n"
    "func_800ADE10:\n"
    "addu $2,$2,$4\n"
    "sll $3,$2,0x3\n"
    "subu $3,$3,$2\n"
    "and $3,$3,$7\n"
    "srl $2,$3,0xf\n"
    "mult $2,$6\n"
    "sw $3,11284($5)\n"
    "mflo $10\n"
    "srl $2,$10,0x10\n"
    "j func_800761D0\n"
    "sltiu $2,$2,20\n"
    ".end func_800ADE10\n.set at\n.set reorder\n");
